#include <iostream>
using namespace std;

class TreeNode {
  public:
      int data;
      TreeNode* left;
      TreeNode* right;

      TreeNode(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
      }
};

int count = 0;

// O(n) time complexity
// O(h) space complexity due to call stack
int kthSmallest(TreeNode* root, int k){
  if(root == NULL){
    return -1;
  }
  if(root->left){
    int leftans = kthSmallest(root->left, k);
    if(leftans != -1){
      return leftans;
    }
  }
  if(count + 1 == k){
    return root->data;
  }
  count++;
  if(root->right){
    int rightans = kthSmallest(root->right, k);
    if(rightans != -1){
      return rightans;
    }
  }
  return -1;
}

int main(){
    TreeNode* root = new TreeNode();
    root->data = 10;
    root->left = new TreeNode();
    root->right = new TreeNode();
    root->left->data = 20;
    root->right->data = 30;
    root->left->left = new TreeNode();
    root->left->right = new TreeNode();
    root->right->left = new TreeNode();
    root->right->right = new TreeNode();
    root->left->left->data = 40;
    root->left->right->data = 50;
    root->right->left->data = 60;
    root->right->right->data = 70;
    cout << "2nd smallest element is " << kthSmallest(root, 2) << endl;
    return 0;
}
