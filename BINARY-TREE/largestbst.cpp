// Largest BST in Binary Tree
#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Info {
public:
    int size;
    int maxi;
    int mini;

    Info(int mx, int mn, int sz) {
        maxi = mx;
        mini = mn;
        size = sz;
    }
};

Info helper(TreeNode* root) {

    // Empty tree is a BST
    if (root == nullptr) {
        return Info(INT_MIN, INT_MAX, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    // Check BST condition
    if (root->data > left.maxi &&
        root->data < right.mini) {

        int currMax = max(root->data, right.maxi);
        int currMin = min(root->data, left.mini);
        int currSize = left.size + right.size + 1;

        return Info(currMax, currMin, currSize);
    }

    // Invalid BST
    return Info(INT_MAX, INT_MIN,
                max(left.size, right.size));
}

int largestBST(TreeNode* root) {
    return helper(root).size;
}

int main() {

    /*
              50
             /  \
           30    60
          / \    / \
         5  20  45 70

    Largest BST:
            60
           /  \
         45    70

    Size = 3
    */

    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(30);
    root->right = new TreeNode(60);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);

    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);

    cout << largestBST(root) << endl;

    return 0;
}