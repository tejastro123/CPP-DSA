#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// O(n) time complexity and O(height) space complexity
void inorder(Node *root, Node *&prev, Node *&first, Node *&second) {
    if(root == nullptr) return;

    inorder(root->left, prev, first, second);

    if(prev != nullptr && prev->data > root->data){
        if(first == nullptr){
            first = prev;
        }
        second = root;
    }

    prev = root;

    inorder(root->right, prev, first, second);
}

void recoverBST(Node* root) {
    Node *prev = nullptr;
    Node *first = nullptr;
    Node *second = nullptr;

    inorder(root, prev, first, second);

    swap(first->data, second->data);
}

// recoverbst using O(1) space complexity by morris traversa  l
// O(n) time complexity and O(1) space complexity
void recoverBST2(Node* root){
    Node* prev = nullptr;
    Node* first = nullptr;
    Node* second = nullptr;

    while(root != nullptr){
        if(root->left == nullptr){
            if(prev != nullptr && prev->data > root->data){
                if(first == nullptr){
                    first = prev;
                }
                second = root;
            }
            prev = root;
            root = root->right;
        }else{
          // find prev (inorder predecessor of root)
            Node* inorderPre = root->left;
            while(inorderPre->right != nullptr && inorderPre->right != root){
                inorderPre = inorderPre->right;
            }
            if(inorderPre->right == nullptr){
                inorderPre->right = root;
                root = root->left;
            }else{
                if(prev != nullptr && prev->data > root->data){
                    if(first == nullptr){
                        first = prev;
                    }
                    second = root;
                }
                inorderPre->right = nullptr;
                prev = root;
                root = root->right;
            }
        }
    }
    // swap data of first and second
    if(first != nullptr && second != nullptr){
        swap(first->data, second->data);
    }
}
// O(n) time complexity and O(height) space complexity
void printInorder(Node *root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->left = new Node(2);

    cout << "Inorder Traversal before recovery: ";
    printInorder(root);
    cout << endl;

    // recoverBST(root);
    recoverBST2(root);

    cout << "Inorder Traversal after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}