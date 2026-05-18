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

vector<int> morisinorderTraversal(TreeNode* curr) {
    vector<int> res;
    while(curr != NULL) {
        if(curr->left == NULL) {
            res.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while(pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            if(pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    vector<int> res = morisinorderTraversal(root);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // output should be 4 2 5 1 3 7
    cout << endl;
    return 0;
}