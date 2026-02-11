#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getcelebrity(vector<vector<int>> arr){
  stack<int> s;
  int n = arr.size();
  for(int i=0; i<n; i++){
    s.push(i);
  }

  while(s.size() > 1){
    int i = s.top();
    s.pop();
    int j = s.top();
    s.pop();
    //if i knows j then i is not celebrity
    if(arr[i][j] == 0){
      s.push(i);
    }
    //if i doesn't know j then j is not celebrity
    else{
      s.push(j);
    }
  }

  int celebrity = s.top();
  s.pop();

  //verify the celebrity
  for(int i=0; i<n; i++){
    if(i != celebrity){
      if(arr[celebrity][i] == 1 || arr[i][celebrity] == 0){
        return -1;
      }
    }
  }
  
  return celebrity;
}
int main() {
  vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};

  int ans = getcelebrity(arr);
  if(ans == -1){
    cout << "No celebrity found" << endl;
  }
  else{
    cout << "Celebrity is " << ans << endl;
  }
  return 0;
}