#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Step 1: Get Inorder Traversal (Sorted Array)
void getInorder(Node* root, vector<int> &res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->data);
    getInorder(root->right, res);
}

// Step 2: Merge two sorted vectors
vector<int> mergeSortedArrays(vector<int> &a, vector<int> &b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);
    return merged;
}

// Step 3: Sorted Array to Balanced BST
Node* sortedArrayToBST(vector<int> &nums, int st, int end) {
    if (st > end) return NULL;
    int mid = st + (end - st) / 2;
    Node* root = new Node(nums[mid]);
    root->left = sortedArrayToBST(nums, st, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> arr1, arr2;
    getInorder(root1, arr1);
    getInorder(root2, arr2);

    vector<int> mergedArr = mergeSortedArrays(arr1, arr2);
    return sortedArrayToBST(mergedArr, 0, mergedArr.size() - 1);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // BST 1: 1, 3
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    // BST 2: 4, 6
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);

    Node* mergedRoot = mergeBSTs(root1, root2);

    cout << "Preorder of merged BST: ";
    preorder(mergedRoot); // Expected: 3 1 2 5 4 6 (or similar balanced structure)
    cout <<endl;  

    vector<int> arr;
    getInorder(mergedRoot, arr);
    cout << "Inorder of merged BST: ";
    for(auto val : arr){
        cout<<val << " ";
    }
    cout <<endl;  
    return 0;
}
