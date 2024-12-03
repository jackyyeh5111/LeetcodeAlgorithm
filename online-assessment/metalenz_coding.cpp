#include <array>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

// Comment/uncomment these to disable/enable each problem

#define PROBLEM_CONVOLUTION
// #define PROBLEM_FRAME_BUFFER

#ifdef PROBLEM_CONVOLUTION
/*
 * PROBLEM 1:
 *
 * Implement a function that applies a 3x3 convolution filter to an image. The
 * image is represented as a 2D array of floats, and the filter kernel is a 3x3
 * matrix of floats. Focus first on correctness; then we can discuss
 * optimization.
 */
std::vector<std::vector<float>> apply_convolution(
    const std::vector<std::vector<float>>& image,
    const std::array<std::array<float, 3>, 3>& kernel) {
    int n_row = image.size();
    int n_col = image[0].size();

    int n_kernel_row = kernel.size();
    int n_kernel_col = kernel[0].size();
    
    int out_row = n_row - n_kernel_row + 1;
    int out_col = n_col - n_kernel_col + 1;
    std::vector<std::vector<float>> out(out_row, std::vector<float>(out_col));

    // convolution
    for (int r = 0; r < out_row; r++) {
      for (int c = 0; c < out_col; c++) {
        float sum = 0.f;
        for (int kr = 0; kr < n_kernel_row; kr++) {
          for (int kc = 0; kc < n_kernel_col; kc++)
            sum += image[r + kr][c + kc] * kernel[kr][kc];
        }
        out[r][c] = sum;
      }
    }
    return out;
}

/*
 * PROBLEM 1 TEST CODE
 *
 */

void print_region(const std::vector<std::vector<float>>& image,
                  size_t start_row, size_t start_col, size_t rows, size_t cols)
{
    for (size_t i = start_row; i < start_row + rows && i < image.size(); i++)
    {
        for (size_t j = start_col; j < start_col + cols && j < image[0].size();
             j++)
        {
            std::cout << image[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void run_convolution_test()
{
    const auto image = std::vector<std::vector<float>> {{1, 2, 3, 4, 5},
                                                        {2, 3, 4, 5, 6},
                                                        {3, 4, 5, 6, 7},
                                                        {4, 5, 6, 7, 8},
                                                        {5, 6, 7, 8, 9}};

    const auto kernel = std::array<std::array<float, 3>, 3> {
        {{{-1, -1, -1}}, {{-1, 8, -1}}, {{-1, -1, -1}}}};

    const auto result = apply_convolution(image, kernel);

    std::cout << "Original center region:\n";
    print_region(image, 1, 1, 3, 3);

    std::cout << "\nConvolved center region:\n";
    print_region(result, 1, 1, 3, 3);
}
#endif

/*
 * END TEST CODE
 */

/*
 * PROBLEM 2:
 * Given a stream of images coming from camera at 60 fps, implement a ring
 * buffer that can store the last N frames while minimizing memory allocation
 * overhead.
 *
 * Bonus/secondary: Include thread-safety considerations.
 *
 */

#ifdef PROBLEM_FRAME_BUFFER
template <typename FrameType>
class FrameBuffer
{
  private:
    FrameType* buffer;       // Pointer to the ring buffer array
    size_t buffer_size;      // Size of the buffer
    size_t ptr_buffer;       // Current index in the buffer
    bool buffer_full;        // Tracks if the buffer is full
    mutable std::mutex mtx;  // Mutex for thread-safety
  public:
    explicit FrameBuffer(size_t buffer_size)
        : buffer(new FrameType[buffer_size]), buffer_size(buffer_size), ptr_buffer(0), buffer_full(false) {}

    ~FrameBuffer() {
        delete[] buffer;  // Properly deallocate the heap-allocated array
    }

    void push_frame(const FrameType& frame) {
        std::lock_guard<std::mutex> lock(mtx); // Ensure thread-safety
        buffer[ptr_buffer] = frame;           // Store the new frame at the current index
        ptr_buffer = (ptr_buffer + 1) % buffer_size; // Move to the next index, circularly
        if (ptr_buffer == 0) buffer_full = true;     // Mark buffer as full when wrapping around
    }
    
    FrameType get_frame(size_t frames_ago) const {
        std::lock_guard<std::mutex> lock(mtx); // Ensure thread-safety
        int ptr = ptr_buffer - 1 - frames_ago;
        if (ptr < 0) ptr = buffer_size + ptr;
        return buffer[ptr];
    }
};

struct TestFrame
{
    int id;
    std::chrono::steady_clock::time_point timestamp;
    TestFrame(int i = 0) : id(i), timestamp(std::chrono::steady_clock::now()) {}
};

/*
 * PROBLEM 2 TEST CODE
 *
 */

void run_frame_buffer_test()
{
    const auto buffer_capacity = 5;
    auto buffer = FrameBuffer<TestFrame> {buffer_capacity};
    const auto num_frames = 7;
    for (int i = 0; i < num_frames; i++)
    {
        buffer.push_frame(TestFrame(i));
    }
    try
    {
        auto frame = buffer.get_frame(0);
        std::cout << "Most recent frame id: " << frame.id << std::endl;

        frame = buffer.get_frame(2);
        std::cout << "Frame from 2 frames ago: " << frame.id << std::endl;
    }
    catch (const std::exception& exc)
    {
        std::cout << "Error: " << exc.what() << "\n";
    }
}
#endif

/*
 * END TEST CODE
 */

int main()
{
#ifdef PROBLEM_FRAME_BUFFER
    run_frame_buffer_test();
#endif

#ifdef PROBLEM_CONVOLUTION
    run_convolution_test();
#endif

    return EXIT_SUCCESS;
}
