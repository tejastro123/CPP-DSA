#include <stack>

class MinStack {
    private stack<int> stack;
    private stack<int> minStack;

    public MinStack() {
        stack = new stack<int>();
        minStack = new stack<int>();
    }
    
    public void push(int val) {
        stack.push(val);
        
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    public void pop() {
        stack.pop();
        minStack.pop();
    }
    
    public int top() {
        return stack.top();
    }
    
    public int getMin() {
        return minStack.top();
    }
}