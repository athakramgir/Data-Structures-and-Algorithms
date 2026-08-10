#include<bits/stdc++.h>
using namespace std;

class Node{ 
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> mergeArray(vector<int> a, vector<int> b) {
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0; 
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[i]){
            ans.push_back(b[i]);
            j++;
        }
    }
    while(i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }
    while(j < b.size()) {
        ans.push_back(b[j]);
        j++;
    }
}

Node* insert(Node* root, int val) {
    if(root == nullptr) {
        return new Node(val);
    }

    Node* newNode = new Node(val);
    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else if(val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(Node* root, vector<int>& in) {
    if(root == nullptr) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* merge2BST(Node* root1, Node* root2) {
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);
    

}
int main(){
    
    return 0;
}