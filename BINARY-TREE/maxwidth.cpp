#include <iostream>
#include <queue>
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

Node* buildTree(vector<int> &preorder, int &idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

int maxWidth(Node* root) { //CBT O(N)
    if (!root) return 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int startIdx = q.front().second;
        int endIdx = q.back().second;

        int levelSize = endIdx - startIdx + 1;
        // cout << "Level size: " << levelSize << endl;
        maxWidth = max(maxWidth, levelSize);

        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front().first;
            int idx = q.front().second;
            q.pop();

            idx = idx - startIdx;

            if (current->left) {
                q.push({current->left, idx * 2 + 1});
            }
            if (current->right) {
                q.push({current->right, idx * 2 + 2});
            }
        }
    }
    return maxWidth;
}

int main() {
    vector<int> preorder = {1, 2, 4, 8, -1, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, 9, -1, -1};
    int idx = 0;
    Node* root = buildTree(preorder, idx);

    cout << "Maximum width of the tree: " << maxWidth(root) << endl;
    return 0;
}