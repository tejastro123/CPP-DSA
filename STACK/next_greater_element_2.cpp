/*The next greater element of some element x in an array is the
first greater element that is to the right of x in the same array.*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {6,8,0,1,3};

    stack<int> s;
    vector<int> ans(arr.size(), 0);
    int n = arr.size();

    for(int i=n-1; i>=0; i--){
        while (s.size()>0 && s.top()<arr[i]){
            s.pop();
        }
        if(s.size()==0){
            ans[i] = -1;
        }
        else{
            ans[i]= s.top();
        }
        s.push(arr[i]);
    }
    //print answer
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}// tc: o(n) sc: o(n) space complexity is o(n) because of the stack 


