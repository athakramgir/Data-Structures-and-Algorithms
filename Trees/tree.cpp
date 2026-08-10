#include<bits/stdc++.h>
using namespace std;


class Node{ 
    public: 
    int val; 
    Node* left; 
    Node* right; 

    Node(int val_) {
        val = val_; 
        right = nullptr; 
        left = nullptr; 
    }
}; 

void inorder(Node* root, vector<int>& tr) { 
    if(root == nullptr) return ;

    inorder(root->left, tr) ; 
    tr.push_back(root->val); 
    inorder(root->right, tr); 
}
int main(){
    int val = 0; 
    cout<< "Enter the value of the root node" << endl; 
    cin >> val; 

    vector<int> inorder_traversal; 
    Node* root = new Node(val); 
    
    inorder(root, inorder_traversal); 
    return 0;
}