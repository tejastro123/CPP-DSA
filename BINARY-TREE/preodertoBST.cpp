#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// O(n) time complexity approach
Node* buildBSTFromPreorder(vector<int>& preorder, int& idx, int minVal, int maxVal) {
  if (idx >= preorder.size()) {
    return NULL;
  }

  int val = preorder[idx];
  if (val < minVal || val > maxVal) {
    return NULL;
  }

  Node* root = new Node(val);
  idx++;

  root->left = buildBSTFromPreorder(preorder, idx, minVal, val);
  root->right = buildBSTFromPreorder(preorder, idx, val, maxVal);

  return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    
    int idx = 0;
    Node* root = buildBSTFromPreorder(preorder, idx, INT_MIN, INT_MAX);

    cout << "Inorder traversal of constructed BST: " << endl;
    inorder(root);  
    
    return 0;
}
