#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
}

TreeNode* prev = NULL;

int minDiffInBST(TreeNode* root) {
  int minDiff = INT_MAX;
  if(root == NULL){
    return INT_MAX;
  }
  if(root->left != NULL){
    int leftmin = minDiffInBST(root->left);
    minDiff = min(minDiff, leftmin);
  }
  if(prev != NULL){
    minDiff = min(minDiff, abs(root->val - prev->val));
  }
  prev = root;
  if(root->right != NULL){
    int rightmin = minDiffInBST(root->right);
    minDiff = min(minDiff, rightmin);
  }
  return minDiff;
}

int main(){

}