// doublt linked list in cpp

#include<iostream>
using namespace std;

class Node{ 
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
    Node* head;
    Node* tail;
    Node* prev;
public:
    DoublyLinkedList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = tail = new_node;
        }
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void push_back(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = tail = new_node;
        }
        else{
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }
        else{
            head->prev = NULL;
            temp->next = NULL;
        }
        delete temp;
    }
    void pop_back(){
        if(tail == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        }
        else{
            tail->next = NULL;
            temp->prev = NULL;
        }
        delete temp;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    DoublyLinkedList dll;

    // dll.push_front(10);
    // dll.push_front(20);
    // dll.push_front(30);

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.print();

    dll.pop_front();
    dll.print();

    dll.pop_back();
    dll.print();
    return 0;

}