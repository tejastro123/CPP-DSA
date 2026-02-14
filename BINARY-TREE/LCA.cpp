//lowest common ancestor
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

Node* buildTree(vector<int> v) {
    int idx = -1;
    idx++;
    if(v[idx] == -1) return NULL;
    
    Node* root = new Node(v[idx]);
    
    root->left = buildTree(v);
    root->right = buildTree(v);
    return root;
}

Node* LCA(Node* root, Node* n1, Node* n2) {
    if(root == NULL) 
      return NULL;

    if(root->data == n1->data || root->data == n2->data) 
      return root;
    
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);
    
    if(leftLCA && rightLCA) {
      return root;
    }
    else if(leftLCA != NULL) {
      return leftLCA;
    }
    else {
      return rightLCA;
    }
}

int main() {
    vector<int> v = { 1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1 };
    Node* root = buildTree(v);
    Node* n1 = new Node(2);
    Node* n2 = new Node(5);
    Node* lca = LCA(root, n1, n2);
    cout << "LCA of " << n1->data << " and " << n2->data << " is " << lca->data << endl;
    return 0;
}