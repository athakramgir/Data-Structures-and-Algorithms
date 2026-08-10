#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data; 
    Node* left; 
    Node* right;
    Node(int x) {
        data = x; 
        left = nullptr; 
        right = nullptr;
    }
}; 
/*-------------------------------Flatten binary tree to a Linked List------------------------------------*/
/*-----Approach 1 - traverse and create new node - not in-Place---------  
-------Appraoch 2 - use recursion - T(n) = O(n), S(n) = O(h) -------------*/
void flatten(Node* root) {
    if(!root) return; 
    flatten(root->left); 
    flatten(root->right); 
    Node* left = root->left; 
    Node* right = root->right; 

    root->left = nullptr; 
    root->right = left; 

    Node* curr = root; 
    while(curr->right) {
        curr = curr->right; 
    }
    curr->right = right; 
}
/*------Approach 3 - Morris Traversal - T(n) = O(n), S(n) = O(1)*/
void flatten2(Node* root) {
    Node* curr= root; 
    Node* prev = nullptr;
    while(curr) {
        if(curr->left) {
            prev = curr->left; 
            while(prev->right){
                prev = prev->right; 
            }
            prev->right = curr->right; 
            curr->right = curr->left; 
            curr->left = nullptr; 
        }
        curr = curr->left; 
    }
}


int main(){
    
    return 0;
}