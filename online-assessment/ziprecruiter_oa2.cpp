/* 
  problem link: https://drive.google.com/file/d/1DGt8lFVaN8tV8_TwAvnSb_1Y8nhmtk5x/view?usp=drive_link
 */
#include "../utils.hpp"

class Solution {
 public:
  vector<int> output(vector<int> &times, int num_max_waiting = 1, int waiting_time = 300) {
    int ptr_finished = 0;
    int queue_size = 0;
    int last_finish_time = 0;
    vector<int> output(times.size());
    for (int i = 0; i < times.size(); i++) {
        // move ptr_finished
        while(ptr_finished < i && output[ptr_finished] <= times[i]) {
            // people leave immediately
            if (output[ptr_finished] != times[ptr_finished])
                queue_size--;
            
            ptr_finished++;
        }
        // check queue_size
        if (queue_size >= num_max_waiting) { // 1
            output[i] = times[i];
            continue;
        }
        
        cout << "ptr_finished: " << ptr_finished << '\n';
        output[i] = max(last_finish_time + waiting_time, times[i] + waiting_time);
        last_finish_time = max(last_finish_time, output[i]);
        queue_size++;
    }
    return output;
  }
};
/* 
      time: [  4, 400, 450, 500]
    output: [304, 700,1000,   0]
               ^
    steps:
        1) move ptr_finished
        2) check queue_size
        3) update queue_size

    variables:
        last_finish_time
        ptr_finished: 1
        queue_size = 1
 */
int main(int argc, char **argv) {

  vector<int> times{4, 400, 450, 500, 700};
  Solution sol;
  vector<int> ans = sol.output(times);
  print (ans);
  
  times = {4, 400, 450, 500, 699};
  ans = sol.output(times);
  print (ans);
//   std::cout << "ans: " << ans << '\n';

  return 0;
}