#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {//O(n)
  deque<int> dq;
  vector<int> res;

  // 1st window
  for(int i = 0; i < k; i++) { //O(k)
    while(!dq.empty() && nums[dq.back()] <= nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }

  // remaining windows
  for(int i = k; i < nums.size(); i++) { //O(n-k)
    res.push_back(nums[dq.front()]);

    // remove elements out of current window
    while(!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    // remove smaller elements than current element
    while(!dq.empty() && nums[dq.back()] <= nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  res.push_back(nums[dq.front()]);
  return res;
}
int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> res = slidingWindowMax(nums, k);
  for(int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}