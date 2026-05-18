#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* buildTree(const vector<int>& preorder, int &idx) {
    if (idx >= preorder.size()) return NULL;

    if (preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void getAllPaths(Node* root, string path, vector<string>& paths) {
    if (!root) return;

    path += to_string(root->data) + " ";

    if (!root->left && !root->right) {
        paths.push_back(path);
        return;
    }
    if(root->left != NULL){
        getAllPaths(root->left, path, paths);
    }
    if(root->right != NULL){
        getAllPaths(root->right, path, paths);
    }
}

void printPre(Node* root){
    if(!root) return;
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};

    int idx = 0;
    Node* root = buildTree(preorder, idx);

    vector<string> paths;
    getAllPaths(root, "", paths);

    cout << "Root to Leaf Paths:\n";
    for (auto &p : paths)
        cout << p << endl;

    cout << "Preorder Traversal:\n";
    printPre(root);
    cout << endl;
    return 0;
}