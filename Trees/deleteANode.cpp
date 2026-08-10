#include<bits/stdc++.h>
using namespace std;

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

Node* insert(Node* root, int val) {
    if(root == nullptr){
        root = new Node(val);
        return root;
    }
    if(root->data > val) {
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* inOrderSuccessor(Node* root){
    while(root->left != nullptr) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int val) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->data > val) {
        root->left = deleteNode(root->left, val);
    }
    else if(root->data < val) {
        root->right = deleteNode(root->right, val);     
    }
    else{
        // case 1
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // case 2
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;

        }
        // case 3 
        Node* is = inOrderSuccessor(root->right);
        root->data = is->data;
        root->right = deleteNode(root->right, is->data);
    }
    return root;
}

void deleteIterative(Node* root, int val) {
    bool flag = false;
    Node* parent = nullptr;
    Node* curr = root;
    while(curr != nullptr && flag == false) {
        if(val < curr->data) {
            parent = curr;
            curr = curr->left;
        }
        else if(val > curr->data){
            parent = curr;
            curr = curr->right;
        }
        else{
            flag = true;
        }
    }
    if(flag == false) cout << "NOT FOUND";

    if(curr->left == nullptr && curr->right == nullptr) {
        if(parent->left == curr){
            parent->left = nullptr;
            delete curr;
        }
        else if(curr == parent->right) {
            parent->right = nullptr;
            delete curr;
        }
    }
    else if(curr->right != nullptr && curr->left != nullptr) {
        Node* temp = inOrderSuccessor(curr->right);
        curr->data = temp->data;
        deleteIterative(curr->right, temp->data);
    }
}
void InOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
int main(){
    vector<int> arr = {5, 1, 3, 4, 2, 7};
    Node* root = nullptr;
    for(int i = 0; i < arr.size(); i++) {
        root = insert(root, arr[i]);
    }
    InOrder(root);
    cout << endl;
   deleteIterative(root, 1);
    InOrder(root);
    return 0;
}