// find predecessor and successor in bst
// O(H) time complexity and O(1) space complexity
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

// Function to insert node in BST
Node* insert(Node* root , int data){
    if(root == NULL){
        return new Node(data);
    }
    if(data < root -> data){
        root -> left = insert(root -> left , data);
    }
    else if(data > root -> data){
        root -> right = insert(root -> right , data);
    }
    return root;
}

// Function to find maximum node in BST
Node* findMax(Node* root){
    Node* ans;
    while(root != NULL){
      ans = root;
      root = root -> right;
    }
    return ans;
}

// Function to find minimum node in BST
Node* findMin(Node* root){
    Node* ans;
    while(root != NULL){
      ans = root;
      root = root -> left;
    }
    return ans;
}

// Function to find predecessor and successor in BST
vector<int> getPredSucc(Node* root , int key){
    Node* pred = NULL;
    Node* succ = NULL;
    Node* curr = root;

    while(curr != NULL){
        if(curr -> data > key){
            succ = curr;
            curr = curr -> left;
        }
        else if(curr -> data < key){
            pred = curr;
            curr = curr -> right;
        }
        else{
            if(curr -> left != NULL){
              // predecessor is largest node in left subtree
                pred = findMax(curr -> left);
            }
            if(curr -> right != NULL){
              // successor is smallest node in right subtree
                succ = findMin(curr -> right);
            }
            break;
        }
    }

    return {pred -> data , succ -> data};
}

int main(){
    Node* root = NULL;
    
    root = insert(root , 50);
    root = insert(root , 30);
    root = insert(root , 20);
    root = insert(root , 40);
    root = insert(root , 70);
    root = insert(root , 60);
    root = insert(root , 80);

    int key = 40;

    vector<int> result = getPredSucc(root , key);
    cout << "Predecessor: " << result[0] << endl;
    cout << "Successor: " << result[1] << endl;

    return 0;
}
