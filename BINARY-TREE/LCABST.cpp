#include <iostream>
#include <vector>
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

// O(log n) time complexity
// O(log n) space complexity
TreeNode* LCABST(TreeNode* root, TreeNode* n1, TreeNode* n2){
  if(root == NULL){
    return NULL;
  }
  // if one is root
  if(root->data == n1->data || root->data == n2->data){
    return root;
  }
  // if both are smaller than root
  if(root->data > n1->data && root->data > n2->data){
    return LCABST(root->left, n1, n2);
  }
  // if both are greater than root
  else if(root->data < n1->data && root->data < n2->data){
    return LCABST(root->right, n1, n2);
  }
  // if one is left and one is right
  else{
    return root;
  }
}

int main(){
    TreeNode* root = new TreeNode(40);

    root->left = new TreeNode(20);
    root->right = new TreeNode(60);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);

    root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(70);

    TreeNode* n1 = root->left->left;   // 10
    TreeNode* n2 = root->left->right;  // 30

    TreeNode* lca = LCABST(root, n1, n2);

    cout << "LCA of "<< n1->data <<" and "<< n2->data<<" is "<<lca->data<< endl;
    return 0;
}