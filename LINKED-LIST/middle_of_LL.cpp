// middle of the linked list

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // slow pointer starts at head
        ListNode* fast = head; // fast pointer also starts at head
        
        while (fast != nullptr && fast->next != nullptr) { // traverse until fast reaches the end
            slow = slow->next; // move slow pointer one step
            fast = fast->next->next; // move fast pointer two steps
        }
        
        return slow; // when fast reaches the end, slow will be at the middle
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6); 

    Solution solution;
    ListNode* middle = solution.middleNode(head);
    
    cout << "Middle node value: " << middle->val << endl; // Output: 3

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}