queue<int> q;
while (!q.empty()) {
  int size = q.size();
  for (int i = 0; i < size; i++) {
    int ele = q.front();
    q.pop();

    /* do something */

    if (condition) q.push(nums[i]);
  }
}