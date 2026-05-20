// BST Iterator

#include <iostream>
#include <stack>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. best optimal solution  
// time complexity : O(1) amortized time complexity 
// space complexity : O(h)

class BSTIterator {
private:
    stack<TreeNode*> st;
    void storeLeftNodes(TreeNode* root) {
        // push all left children of the root node
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    // Returns the next smallest number
    int next() {
        TreeNode* top = st.top();
        st.pop();
        storeLeftNodes(top->right);
        return top->data;
    }
    // Returns true if there exists a next smallest number
    bool hasNext() {
        return !st.empty();
    }
};   

// 2. time complexity : O(n)
// space complexity : O(n)

class BSTIterator2 {
private:
    vector<int> inorder;
    int index;
    void Inorder(TreeNode* node) {
        if (node == nullptr) return;
        Inorder(node->left);
        inorder.push_back(node->data);
        Inorder(node->right);
    }

public:
    BSTIterator2(TreeNode* root) : index(0) {
        Inorder(root);
    }
    int next() {
        if (hasNext()) {
            return inorder[index++];
        }
        return -1; // Should not happen in valid use
    }
    bool hasNext() {
        return index < inorder.size();
    }
};

int main(){
    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(12);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(25);

    auto start1 = high_resolution_clock::now();
    BSTIterator it1(root);
    cout << "BSTIterator1:";
    while (it1.hasNext()) {
        cout << it1.next() << " ";
    }
    cout << endl; 
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
    cout << "Time taken by BSTIterator1: " << duration1 << " nanoseconds" << endl;

    auto start2 = high_resolution_clock::now();
    BSTIterator2 it2(root);
    cout << "BSTIterator2:";
    while (it2.hasNext()) {
        cout << it2.next() << " ";
    }
    cout << endl;
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
    cout << "Time taken by BSTIterator2: " << duration2 << " nanoseconds" << endl;
    return 0;
}