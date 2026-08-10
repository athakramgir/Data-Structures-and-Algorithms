#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;  
};
int countNodes(Node* tree) {
        if(tree == nullptr) return 0;
        
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    } 
    bool isCBT(Node* root, int i, int t) {
        if(root == nullptr) return true;
        if(i > t) {return false;}
        else {
            bool left = isCBT(root->left, 2*i + 1, t);
            bool right = isCBT(root->right, 2*i + 2, t);
            return left && right;
        }
    }
    bool isMaxOrder(Node* root) {
        if(root->left == nullptr && root->right == nullptr) {
            return true;
        }
        else if(root->right == nullptr) {
            return root->data > root->left->data;
        }
        else {
            return root->data > root->left->data && root->data > root->right->data && isMaxOrder(root->left) && isMaxOrder(root->right);
        }
    }
    bool isHeap(Node* tree) {
        // code here
        int index = 0; 
        int total = countNodes(tree);
        if(isCBT(tree, index, total) && isMaxOrder(tree)){
            return true;
        } else { 
            return false;
        }
    }
int main(){
    
    return 0;
}