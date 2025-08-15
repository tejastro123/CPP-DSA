//You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. 
// This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. 
// These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.
// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
// Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.
// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

# include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;
        while (curr != NULL){
            if (curr->child != NULL){

                //flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }
                //attach tail with the next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }  
};

int main(){
    //create a doubly linked list
    Node* head = new Node();
    head->val = 1;
    head->prev = NULL;
    head->next = NULL;
    head->child = NULL;
    //add nodes to the list
    Node* node2 = new Node();
    node2->val = 2;
    node2->prev = head;
    node2->next = NULL;
    node2->child = NULL;
    head->next = node2;
    //add child nodes   
    Node* node3 = new Node();
    node3->val = 3;
    node3->prev = NULL;
    node3->next = NULL;
    node3->child = NULL;
    Node* node4 = new Node();
    node4->val = 4;
    node4->prev = NULL;
    node4->next = NULL;
    node4->child = NULL;
    Node* node5 = new Node();
    node5->val = 5;
    node5->prev = NULL;
    node5->next = NULL;
    node5->child = NULL;
    node3->child = node4;
    node4->child = node5;
    //print the list

    return 0;
}

