#include "../utils.hpp"

void test(const unordered_map<int, int> &um) {
    // cout << um[0] << '\n';
    auto it = um.find(0);
    if (it != um.end()) 
        cout << "val: " << it->second << '\n';
    cout << um.at(0) << '\n';
}

int main() {
  unordered_map<int, int> um{{0, 100}};
  test(um);
  return 0;
}