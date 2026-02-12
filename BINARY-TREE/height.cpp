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
Node* buildTree(vector<int> order) {//O(n)
  idx++;
  if(order[idx] == -1) {
      return NULL;
  }
  Node* root = new Node(order[idx]);
  root->left = buildTree(order);
  root->right = buildTree(order);
  return root;
}

//height of the tree
int height(Node* root) {//O(n)
    if(root == NULL) {
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht, rightht) + 1;
}

//count nodes
int countNodes(Node* root) {//O(n)
    if(root == NULL) {
        return 0;
    }

    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);
    return leftcount + rightcount + 1;
}

//sum of nodes
int sumNodes(Node* root) {//O(n)
    if(root == NULL) {
        return 0;
    }

    int leftsum = sumNodes(root->left);
    int rightsum = sumNodes(root->right);
    return leftsum + rightsum + root->data;
}

int main() {
    vector<int> order = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(order);

    int ht = height(root);
    cout << "Height of the tree is: " << ht << endl;

    int nodes = countNodes(root);
    cout << "Number of nodes in the tree is: " << nodes << endl;

    int sum = sumNodes(root);
    cout << "Sum of nodes in the tree is: " << sum << endl;
    return 0;
}