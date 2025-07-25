// delete cycle in linked list
#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
};
class Solution {
public:
    void deleteCycle(node *head) {
        if (head == NULL || head->next == NULL) return; // No cycle possible
        node *slow = head;
        node *fast = head;                                                                                          
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow one step at a time
            fast = fast->next->next; // Move fast two steps at a time
            if (slow == fast) { // Cycle detected
                break;
            }
        }
        if (slow != fast) return; // No cycle found
        // Find the start of the cycle
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next; // Move slow one step at a time
            fast = fast->next; // Move fast one step at a time
        }
        // Now fast is at the last node of the cycle
        fast->next = NULL; // Break the cycle
    }
};
int main() {
    Solution solution;

    // Example usage
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    // Creating a cycle for testing
    head->next->next->next->next->next = head; // 5 points to 3

    solution.deleteCycle(head);

    // Check if the cycle is deleted
    node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl; // Should print 1 2 3 without any cycle

    // Clean up memory (not shown here, but should be done in real applications)
    
    return 0;
}
