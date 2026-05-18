#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* nextright = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return;
    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = nextright;
    nextright = root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    flatten(root);
    // output : 1 2 3 4 5 6
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}