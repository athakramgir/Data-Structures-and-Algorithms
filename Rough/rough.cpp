#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if(root == nullptr) return new Node(val);

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    if(val > root->data) root->right = insert(root->right, val);

    return root;
}
Node* arraytoBST(int array[], int n) {
    int x = n/2 + 1;
    Node* root = new Node(array[x]);

    for(int i = 0; i < n; i++) {
        if(i == x) continue;
        root = insert(root, array[i]);
    }
    return root;
}
void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    int n = 0; 
    cout << "Enter the value of n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array \n";
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    Node* ans = arraytoBST(array, n);
    inorder(ans);

    return 0;
}