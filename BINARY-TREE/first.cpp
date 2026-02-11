#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> &preorder) {//O(n)
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void printTree(Node* root) {//O(n)
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};//root left right
    
    Node* root = buildTree(preorder);
    printTree(root);

    return 0;
}