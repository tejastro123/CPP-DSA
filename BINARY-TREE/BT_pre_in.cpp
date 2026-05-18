#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int search(vector<int>& inorder, int left, int right, int target){
    for(int i = left; i <= right; i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}

Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
    if(left > right){
        return NULL;
    }

    Node* root = new Node(preorder[preIdx++]);

    int inIdx = search(inorder, left, right, root->data);
    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);
    
    return root;  
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    int left = 0;
    int right = inorder.size() - 1;
    return helper(preorder, inorder, preIdx, left, right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    Node* root = buildTree(preorder, inorder);
    // print the preorder and inorder
    cout << "Preorder: ";
    for(int i = 0; i < preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;
    cout << "Inorder: ";
    for(int i = 0; i < inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;
    return 0;
}
