// merge two sorted lists in cpp
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        if(head1->val < head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
}; // tc = O(n+m), sc = O(1)

int main(){
    // create sorted lists
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    // create another sorted list
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);
    // merge two sorted lists
    Solution solution;
    ListNode* merged = solution.mergeTwoLists(head1, head2);
    // print merged list
    while(merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    return 0;
}