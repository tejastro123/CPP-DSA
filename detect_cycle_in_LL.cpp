// detect cycle in linked list

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow pointer by 1 step
            fast = fast->next->next;   // Move fast pointer by 2 steps
            
            if (slow == fast) {        // If they meet, there is a cycle
                return true;
            }
        }
        return false;                 // If we reach here, no cycle exists
    }
};

int main() {
    Solution solution;

    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Creates a cycle

    if (solution.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    // Clean up memory (not shown here, but should be done in real applications)
    
    return 0;
}