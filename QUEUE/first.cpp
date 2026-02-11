#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

class Queue{
  public:
    Node* front;
    Node* rear;
    Queue(){
      this->front = NULL;
      this->rear = NULL;
    }
    void push(int data){//O(1)
      Node* newNode = new Node(data);
      if(front == NULL){
        front = newNode;
        rear = newNode;
      }else{
        rear->next = newNode;
        rear = newNode;
      }
    }
    void pop(){//O(1)
      if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
      }
      Node* temp = front;
      front = front->next;
      delete temp;
    }
    int first(){//O(1)
      if(front == NULL){
        cout << "Queue is empty" << endl;
        return -1;
      }
      return front->data;
    }
    void display(){//O(n)
      if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
      }
      Node* temp = front;
      while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);

  q.display();
  q.pop();
  q.display();
  cout << "Front element is: " << q.first() << endl;

  return 0; 
}