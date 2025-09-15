 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Stack {
    vector<int> v;
public:
    void push(int x) {
        v.push_back(x);
    }
    int pop() {
        if(v.empty()) {
            return -1;
        }
        int x = v.back();
        v.pop_back();
        return x;
    }
    int top() {
        if(v.empty()) {
            return -1;
        }
        return v.back();    
    }
    int size() {
        return v.size();
    }
    bool empty() {
        return v.size()==0;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}