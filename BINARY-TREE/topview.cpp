#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildTree(vector<int> &preorder) {//O(n)
    static int idx = -1;
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void topview(Node* root) {//O(n)
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while(!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        if(curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
}

int main() { 
    vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(v);
    topview(root);
    return 0;
}