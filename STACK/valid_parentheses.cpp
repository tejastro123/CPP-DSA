
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        stack<char> st;

        for(int i=0; i<n; i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[' ) {//opening
                st.push(str[i]);
            }
            else{
                if(st.empty()) return false;
                char top = st.top();

                if( (top == '(' && str[i] == ')') || 
                    (top == '{' && str[i] == '}') ||
                    (top == '[' && str[i] == ']') ) {
                         st.pop();
                }
                else return false;
            }
        }   
        return st.empty();
    }
};

int main(){
    Solution s;
    string str = "({[]})";
    cout<<s.isValid(str)<<endl;
    return 0;
}