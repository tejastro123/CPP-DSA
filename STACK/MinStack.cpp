#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {
        // Default constructor
    }
    
    void push(int val) {
        s.push(val);
        
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        if (s.empty()) return;
        s.pop();
        minStack.pop();
    }
    
    int top() {
        if (s.empty()) return -1; // Or throw exception
        return s.top();
    }
    
    int getMin() {
        if (minStack.empty()) return -1; // Or throw exception
        return minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "Min: " << ms.getMin() << endl; // return -3
    ms.pop();
    cout << "Top: " << ms.top() << endl;    // return 0
    cout << "Min: " << ms.getMin() << endl; // return -2
    return 0;
}