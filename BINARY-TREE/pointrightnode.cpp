// connect nodes at same level
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int val){
        data = val;
        left = right = next = nullptr;
    }
};

// iterative approach O(n) time and O(1) space
TreeNode* connect(TreeNode* root){ 
    if(root == nullptr) return nullptr;

    TreeNode* leftmost = root;
    while(leftmost != nullptr){
        TreeNode* curr = leftmost;
        while(curr != nullptr){
            if(curr->left){
                curr->left->next = curr->right;
            }
            if(curr->right){
                curr->right->next = curr->next ? curr->next->left : nullptr;
            }
            curr = curr->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}

// bfs approach O(n) time and O(n) space
TreeNode* connectbfs(TreeNode* root) {
  if (root == nullptr) return nullptr;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    TreeNode* prev = nullptr;

    for (int i = 0; i < size; i++) {
        TreeNode* curr = q.front();
        q.pop();
        // connect previous node with current
        if (prev != nullptr) {
            prev->next = curr;
        }
        prev = curr;
        // push children
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }
    // last node of level points to NULL
    if (prev != nullptr) {
        prev->next = nullptr;
    }
  }
  return root;
}

void printLevels(TreeNode* root) {

    while (root != nullptr) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        root = root->left;
    }
}

int main(){
   /*
                1
             /     \
            2       3
          /   \   /   \
         4     5 6     7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    connect(root);

    printLevels(root);
    return 0;
}