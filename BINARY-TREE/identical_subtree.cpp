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
};

int idx = -1;
Node* buildTree(vector<int> order) {
  idx++;
  if(order[idx] == -1) {
      return NULL;
  }
  Node* root = new Node(order[idx]);
  root->left = buildTree(order);
  root->right = buildTree(order);
  return root;
}

bool isIdentical(Node* root1, Node* root2) {
  if(root1 == NULL || root2 == NULL) {
    return root1 == root2;
  }
  
  bool isleftsame = isIdentical(root1->left, root2->left);
  bool isrightsame = isIdentical(root1->right, root2->right);
  return isleftsame && isrightsame && root1->data == root2->data;
}

bool isSubtree(Node* root, Node* subRoot) {
  if(root == NULL || subRoot == NULL) {
    return root == subRoot;
  }

  if(root->data == subRoot->data && isIdentical(root, subRoot)) {
    return true;
  }

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    vector<int> order1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> order2 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root1 = buildTree(order1);
    idx = -1;
    Node* root2 = buildTree(order2);

    bool ans = isIdentical(root1, root2);
    bool ans2 = isSubtree(root1, root2);
    cout << ans << endl;
    cout << ans2 << endl;

    return 0;
}

    