#include <iostream>
#include <deque>
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

class Deque{
  public:
    Node* front;
    Node* rear;
    Deque(){
      this->front = NULL;
      this->rear = NULL;
    }
    void push_front(int data){//O(1)
      Node* newNode = new Node(data);
      if(front == NULL){
        front = newNode;
        rear = newNode;
      }
      else{
        newNode->next = front;
        front = newNode;
      }
    }
    void push_back(int data){//O(1)
      Node* newNode = new Node(data);
      if(front == NULL){
        front = newNode;
        rear = newNode;
      }
      else{
        rear->next = newNode;
        rear = newNode;
      }
    }
    void pop_front(){//O(1)
      if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
      }
      Node* temp = front;
      front = front->next;
      delete temp;
    }
    void pop_back(){//O(n)
      if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
      }
      Node* temp = front;
      while(temp->next != rear){
        temp = temp->next;
      }
      temp->next = NULL;
      rear = temp;
      delete temp;
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
  Deque dq;
  dq.push_front(1);
  dq.push_front(2);

  dq.push_back(3);
  dq.push_back(4);

  dq.display();
  
  dq.pop_front();
  dq.pop_back();
  
  dq.display();
  return 0; 
}