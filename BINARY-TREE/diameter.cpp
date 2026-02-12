#include <iostream>
#include <vector>
using namespace std;

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

Node* buildTree(vector<int> &v) {//O(n)
    static int idx = -1;
    idx++;
    if(v[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(v[idx]);
    root->left = buildTree(v);
    root->right = buildTree(v);
    return root;
}

//height of the tree
int height(Node* root) {//O(n)
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node* root) {//O(n^2)
    if(root == NULL) {
        return 0;
    }

    int leftdia = diameter(root->left);
    int rightdia = diameter(root->right);
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currDia = leftHeight + rightHeight;
    return max(currDia, max(leftdia, rightdia));
} 

int main() {
    vector<int> v = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1};
    Node* root = buildTree(v);
    cout << diameter(root) << endl;
    return 0;
}