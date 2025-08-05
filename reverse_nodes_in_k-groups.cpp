# include<iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Check if there are at least k nodes to reverse
        while (cnt < k) {
            if (temp == NULL) {
                return head;  // Not enough nodes, return as-is
            }
            temp = temp->next;
            cnt++;
        }

        // Recursively call for the remaining list after k nodes
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse current group of k nodes
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};

int main(){
    
}