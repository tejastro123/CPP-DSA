// reverse a linked list
#include <iostream>
using namespace std;    

//  Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; // previous node
        ListNode* curr = head; // current node
        ListNode* next = NULL; // next node
        while (curr != NULL) { // traverse until end of list
            next = curr->next; // store next node
            curr->next = prev; // reverse current node's next pointer
            prev = curr; // move prev to current node
            curr = next; // move to next node   
    }
        return prev; // return new head (previous node)
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1); // create a linked list 1 -> 2 -> 3
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // Print original linked list
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " "; // should print 1 2 3
        temp = temp->next;
    }
    cout << endl;
    
    ListNode* reversedHead = solution.reverseList(head); // reverse the linked list
    
    // Print reversed linked list
    ListNode* temp2 = reversedHead;
    while (temp2 != NULL) {
        cout << temp2->val << " "; // should print 3 2 1
        temp2 = temp2->next;
    }
    cout << endl;
    
    return 0;
}