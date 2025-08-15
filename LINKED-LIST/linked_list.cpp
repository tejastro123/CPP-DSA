// single linked list implementation
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL ;
    }
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) {
        Node* newnode = new Node(val); // allocate memory for new node
        if (head == NULL) {
            head = newnode; // if list is empty, set head to new node
            tail = newnode; // and tail to new node
            return;
        } else {
            newnode->next = head; // link new node to current head
            head = newnode; // update head to new node
            return;
        }
    }
    void push_back(int val) {
        Node* newnode = new Node(val); // allocate memory for new node
        if (head == NULL) {
            head = newnode; // if list is empty, set head to new node
            tail = newnode; // and tail to new node
            return;
        } else {
            tail->next = newnode; // link current tail to new node
            tail = newnode; // update tail to new node
            return;
        }
    }
    void pop_front() {
        if (head == NULL) {
            cout << "List is empty, cannot pop front." << endl;
            return;
        }
        Node* temp = head; // store current head
        head = head->next; // update head to next node
        temp->next = NULL; // disconnect old head
        delete temp; // free memory of old head
    }
    void pop_back() {
        if (head == NULL) {
            cout << "List is empty, cannot pop back." << endl;
            return;
        }
        if (head->next == NULL) { // if only one node exists
            delete head; // free memory of head
            head = NULL; // set head to NULL
            tail = NULL; // set tail to NULL
            return;
        }
        Node* temp = head; // start from head
        while (temp->next != tail) { // traverse to second last node
            temp = temp->next; // move to next node
        }
        temp->next = NULL; // set second last node's next to NULL
        delete tail; // free memory of last node
        tail = temp; // update tail to second last node
    } 
    void insert( int val, int pos) { // tc O(n), sc O(1)
        if(pos<0){
            cout << "INVALID Position." << endl;
            return;
        }
        if (pos == 0) {
            cout << "Position cannot be NULL." << endl;
            return;
        }
        Node* temp = head; // start from head
        for(int i = 0; i<pos-1; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                return; // if position is out of bounds
            }
            temp = temp->next; // traverse to the position
        }
        Node* newnode = new Node(val); // allocate memory for new node
        newnode->next = temp->next; // link new node to next node
        temp->next = newnode; // link current node to new node
        if (newnode->next == NULL) { // if new node is at the end
            tail = newnode; // update tail to new node  
        }
        
    }
    void search(int val) { // tc O(n), sc O(1)
        Node* temp = head; // start from head
        int idx = 0; // initialize index
        while (temp != NULL) { // traverse until end of list
            if (temp->data == val) { // if value found
                cout << "Value " << val << " found in the list." << endl;
                cout << "Index: " << idx << endl; // print index
                return;
            }
            temp = temp->next; // move to next node
            idx++; // increment index
        }
        cout << "Value not found in the list." << endl; // if value not found
    } 
    void print_list() { // tc O(n), sc O(1)
        Node* temp = head; // start from head
        while (temp != NULL) { // traverse until end of list
            cout << temp->data << " "; // print current node's data
            temp = temp->next; // move to next node
        }
        cout << endl; // print newline at the end
    }
    
};

int main(){
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_back(40);
    list.print_list(); 
    list.pop_front();
    list.print_list();
    list.pop_back();
    list.print_list();
    list.insert(25, 1);
    list.print_list();
    list.search(25);

    return 0;   

}
