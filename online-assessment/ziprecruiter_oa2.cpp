/*
  problem link:
  https://drive.google.com/file/d/1DGt8lFVaN8tV8_TwAvnSb_1Y8nhmtk5x/view?usp=drive_link
 */
#include "../utils.hpp"

class Solution {
 public:
  vector<int> output(vector<int> &times, int num_max_waiting = 1,
                     int waiting_time = 300) {
    int last_finish_time = 0;
    int ptr_processing = 0;
    int queue_size = 0;
    vector<int> finished_times(times.size(), 0);

    for (int i = 0; i < times.size(); i++) {
      while (ptr_processing < i && times[i] >= finished_times[ptr_processing]) {
        // udpate ptr_processing
        if (times[ptr_processing] != finished_times[ptr_processing])
          queue_size--;
        ptr_processing++;
      }

      if (queue_size > num_max_waiting) {
        finished_times[i] = times[i];
        continue;
      }
      
      // update variables
      if (times[i] < last_finish_time) {
        last_finish_time = last_finish_time + waiting_time;
        queue_size++;
      }
      else {
        last_finish_time = times[i] + waiting_time;
      }
      finished_times[i] = last_finish_time;
    }
    return finished_times;
  }
};
/*
      time: [  4, 400, 450, 800]
    output: [304, 700,1000, 800]
                        ^
    steps:
        1) move ptr_processing
        2) check queue_size
        3) update queue_size

    variables:
        last_finish_time
        ptr_processing
        queue_size
 */
int main(int argc, char **argv) {
  vector<int> times{4, 400, 450, 500, 700};
  Solution sol;
  vector<int> ans = sol.output(times);
  print (times);
  print(ans);

  times = {4, 400, 450, 500, 699};
  ans = sol.output(times);
  print (times);
  print(ans);
  //   std::cout << "ans: " << ans << '\n';

  return 0;
}