#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
  queue<int> q;
  unordered_map<char, int> mp;
  int n = s.size();
  
  for(int i = 0; i < n; i++) {
    if(mp.find(s[i]) == mp.end()) {
      q.push(i);
    }

    mp[s[i]]++;
    while(!q.empty() && mp[s[q.front()]] > 1) {
      q.pop();
    }
  }
  return q.empty() ? -1 : q.front();
}

int main() {
  string s = "leetcode";
  cout << firstUniqChar(s) << endl;
  return 0;
}
