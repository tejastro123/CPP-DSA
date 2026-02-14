#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
} Node;


Node* buildTree(vector<int> &preorder) {//O(n)
    static int idx = -1;
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void kthLevel(Node* root, int k) {
    if(root == NULL) return;
    
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}

int main() {
    vector<int> v = {1, 2, -1,-1,3, 4,-1,-1,5,-1,-1};
    Node* root = buildTree(v);
    kthLevel(root, 2);
    return 0;
}