#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
      int data;
      Node* left;
      Node* right;

      Node(int d) {
          this->data = d;
          this->left = NULL;
          this->right = NULL;
      }
}

bool helper(Node* root, Node* min, Node* max ){
  if(root == NULL) {
    return true;
  }
  
  if(min != NULL && root->data <= min->data) {
    return false;
  }
  if(max != NULL && root->data >= max->data) {
    return false;
  }

  return helper(root->left, min, root) && helper(root->right, root, max);

}

bool isBST(Node* root) {
  return helper(root, NULL, NULL);
}
