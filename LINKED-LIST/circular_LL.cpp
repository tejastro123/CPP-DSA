// circular linked list in cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;
public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void insertAtHead(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }
    void insertAtTail(int val){
        Node* newnode = new Node(val);
        if(tail == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }
    void deleteAtHead(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;    
        }
    }
    void deleteAtTail(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void print(){
        if(head == NULL) return;

        cout<< head->data<<"->";
        Node* temp = head->next;

        while(temp != head){
            cout<< temp->data<<"->";
            temp = temp->next;
        }
        cout<< temp->data << endl;
    }
};

int main(){
    CircularLinkedList cll;

    // cll.insertAtHead(10);
    // cll.insertAtHead(20);
    // cll.insertAtHead(30);
    // cll.print();

    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cll.print();

    cll.deleteAtHead();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    return 0;
}