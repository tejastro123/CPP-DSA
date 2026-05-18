#include <iostream>
#include <vector>
using namespace std;

// create node
class Node {
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

// insert node O(log n)
Node* insert(Node* root, int val) {
  if(root == NULL) {
    return new Node(val);
  }
  if(val < root->data) {
    root->left = insert(root->left, val);
  }
  else {
    root->right = insert(root->right, val);
  }
  return root;
}

// biuld bst
Node* buildBST(vector<int> order) {
   Node* root = NULL;
  for(int i = 0; i < order.size(); i++) {
    root = insert(root, order[i]);
  }
  return root;
}

// print inorder bst O(n)
void inorder(Node* root) {
  if(root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// search for key - O(logn)
bool search(Node* root, int key) {
  if(root == NULL) {
    return false;
  }
  if(root->data == key) {
    return true;
  }
  if(key < root->data) {
    return search(root->left, key);
  }
  return search(root->right, key);
}

// get inorder successor = left most node in right subtree
Node* getInorderSuccessor(Node* root) {
  while(root!= NULL && root->left != NULL) {
    root = root->left;
  }
  return root;
}

// delete node O(log n)
Node* deleteNode(Node* root, int key) {
  if(root == NULL) {
    return NULL;
  }
  if(key < root->data) {
    root->left  = deleteNode(root->left, key);
  }
  else if(key > root->data) {
    root->right = deleteNode(root->right, key);
  }
  else {
    //  key = root
    if(root->left == NULL) {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    else { // 2 children
      Node* succ = getInorderSuccessor(root->right);
      root->data = succ->data;
      root->right = deleteNode(root->right, succ->data);
    }
  }
  return root;
}

int main() {
  vector<int> order = {3,2,1,5,6,4};

  Node* root = buildBST(order);
  cout << "Before: ";
  inorder(root);
  cout << endl;

  cout << "After: ";
  root = deleteNode(root, 5);
  inorder(root);
  cout << endl;

  cout << "Search: ";
  cout << search(root, 5) << endl;

  return 0;
}