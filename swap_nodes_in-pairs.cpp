
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { //tc = O(n), sc = O(1)
public:
    ListNode* swapPairs(ListNode* head) {
        if(head ==NULL || head->next == NULL){
            return head;       
        }
        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while ((first != NULL && sec != NULL)){
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = sec;
            }
            else{
                head = sec;
            }

            //update
            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            }
            else{
                sec = NULL;
            }
        }
        return head;
    }
};

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);

    // Print original list
    cout << "Original List: ";
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Swapping pairs
    Solution sol;
    ListNode* newHead = sol.swapPairs(head);

    // Print swapped list
    cout << "Swapped List: ";
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
