#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
  public:
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// O(n)
TreeNode* helper(vector<int>& nums, int st, int end){
  if(st > end) {
    return NULL;
  }
  int mid = st + (end - st)/2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = helper(nums, st, mid - 1);
  root->right = helper(nums, mid + 1, end);
  return root;
}

// O(n)
TreeNode* sortedArrayToBST(vector<int>& nums){
  if(nums.size() == 0) {
    return NULL;
  }
  return helper(nums, 0, nums.size() - 1);
}

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
  vector<int> nums = {-10, -3, 0, 5, 9};
  TreeNode* root = sortedArrayToBST(nums);
  // print tree
  inorder(root);
  return 0;
}