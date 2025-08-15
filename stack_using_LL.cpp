 
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

class Stack {
    list<int> ll;
public:
    void push(int x) {
        ll.push_front(x);
    }
    void pop() {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            exit(1);
        }
        int x = ll.front();
        ll.pop_front();
    }
    int top() {
        if(ll.empty()) {
            return -1;
        }
        return ll.front();
    }
    int size() {
        return ll.size();
    }
    bool empty() {
        return ll.size()==0;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }
    cout << endl;
    return 0;
}