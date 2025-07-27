// delete cycle in linked list
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return NULL;

        slow = head;
        ListNode *prev = NULL;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL; // Remove the cycle by setting the last node's next to NULL
        return slow; // The start of the cycle
        
    }
};

int main() {
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution sol;
    ListNode *startOfCycle = sol.detectCycle(head);
    
    if (startOfCycle) {
        cout << "Cycle detected starting at node with value: " << startOfCycle->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    //print the modified list
    ListNode *current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;   

    return 0;
}