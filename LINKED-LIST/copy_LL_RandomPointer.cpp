
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> map;

        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        map[head] = newhead;

        while (oldtemp != NULL) {
            Node* copynode = new Node(oldtemp->val);
            map[oldtemp] = copynode;
            newtemp->next = copynode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        
        oldtemp = head;
        newtemp = newhead;
        while (oldtemp != NULL) {
            newtemp->random = map[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;

    }
};


int main(){
    Solution solution;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next->next->next;
    head->next->random = head;
    head->next->next->random = head;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next;
    Node* newhead = solution.copyRandomList(head);
    while (newhead != NULL) {
        cout << newhead->val << " ";
        newhead = newhead->next;
    }

    return 0;
}