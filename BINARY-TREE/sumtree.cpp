#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Build tree from preorder (-1 means NULL)
Node* buildTree(vector<int> &preorder, int &idx) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);
    return root;
}

// Convert to Sum Tree
int SumTree(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        int val = root->data;
        root->data = 0;
        return val;
    }

    int leftsum = SumTree(root->left);
    int rightsum = SumTree(root->right);

    int old_val = root->data;
    root->data = leftsum + rightsum;

    return root->data + old_val;
}

// Print tree root-left-right
void printpreOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printpreOrder(root->left);
    printpreOrder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 3, 5, -1, -1, 6, -1, -1};

    int idx = -1;
    Node* root = buildTree(preorder, idx);

    SumTree(root);

    cout << "Sum Tree (PreOrder): ";
    printpreOrder(root);
    cout << endl;

    return 0;
}