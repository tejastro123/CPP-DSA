#include <iostream>
using namespace std;

class CircularQueue{
  public:
    int* arr;
    int front;
    int rear;
    int currsize;
    int cap;
    CircularQueue(int size){
      this->cap = size;
      arr = new int[cap];
      front = -1;
      rear = -1;
    }
    void push(int data){
      if(currsize == cap){
        cout << "Queue is full" << endl;
        return;
      }
      if(front == -1){
        front = 0;
      }
      rear = (rear + 1) % cap;
      arr[rear] = data;
      currsize++;
    }
    void pop(){
      if(front == -1){
        cout << "Queue is empty" << endl;
        return;
      }
      if(front == rear){
        front = -1;
        rear = -1;
      }
      else{
        front = (front + 1) % cap;
      }
      currsize--;
    }
    int first(){
      if(front == -1){
        cout << "Queue is empty" << endl;
        return -1;
      }
      return arr[front];
    }
    void display(){
      if(front == -1){
        cout << "Queue is empty" << endl;
        return;
      }
      int i = front;
      while(i != rear){
        cout << arr[i] << " ";
        i = (i + 1) % cap;
      }
      cout << arr[rear] << endl;
    }
};

int main() {
  CircularQueue cq(5);
  cq.push(1);
  cq.push(2);
  cq.push(3);
  cq.push(4);
  cq.push(5);

  cq.display();
  cq.pop();
  cq.pop();
  cq.display();
  
  return 0; 
}