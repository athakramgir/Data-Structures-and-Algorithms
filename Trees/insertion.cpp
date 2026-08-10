#include<bits/stdc++.h>
using namespace std;
// binary search trees
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

Node* insertionIterative(Node* root, int val){
    Node* newNode = new Node(val);
    if(root == nullptr) {
        return newNode;
    }
    Node* parent = nullptr;
    Node* current = root;
    while(current != nullptr) {
        parent = current;
        if(val < current->data){
            current = current->left;
        }
        else if(val > current->data) {
            current = current->right;
        }
        else{
            delete newNode;// duplicate values 
            return root;
        }
    }
    if(val < parent->data) {
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    return root;
}
Node* insertRecursive(Node* root, int val) {
    if(root == nullptr){
        root = new Node(val);
        return root;
    }
    if(root->data > val) {
        root->left = insertRecursive(root->left, val);
    }
    else{
        root->right = insertRecursive(root->right, val);
    }
    return root;
}


int main(){
    
    return 0;
}