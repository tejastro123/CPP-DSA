#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//build tree from preorder traversal
int idx = -1;
Node* buildTree(vector<int> order) {
    idx++;
    Node* root = new Node(order[idx]);
    if(order[idx] == -1) {
        return NULL;
    }
    root->left = buildTree(order);
    root->right = buildTree(order);
    return root;
}

//preorder traversal
void preOrder(Node* root) {//O(n)
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversal
void inOrder(Node* root) {//O(n)
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//postorder traversal
void postOrder(Node* root) {//O(n)
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//level order traversal
void levelOrder(Node* root) {//O(n)
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
              cout << endl;
              q.push(NULL);
              continue;
            }
            else {
                break;
            }
        }

        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    vector<int> order = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};//simple binary tree
    Node* root = buildTree(order);

    preOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    return 0;
}