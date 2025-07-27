// circular linked list in cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;
    Node* tail;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtHead(int val){
        Node* newnode = new Node(val);
        if(tail == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
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
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtHead(30);
    cll.print();
    return 0;
}