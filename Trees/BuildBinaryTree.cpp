#include<iostream>
#include<vector>

using namespace std;
// build binary tree
// search in binary search trees (iterative)
// search in binary search trees (recursive)
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
void inOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void Search(Node* root, int item) {
    bool flag = false;
    while(root != nullptr && flag == false) {
        if(root->data > item) {
            root = root->left;
        }
        else if(root->data < item){
            root = root->right;
        }
        else if(root->data == item) {
            flag = true;
        }
    }
    if(flag == true) {
        cout << "search successful for " << item << endl;
    }
    else{
        cout << "Search Unsuccessful for "<< item << endl;
    }
}

bool SearchRecursive(Node* root, int key) {
    if(root == nullptr){
        return false;
    }
    if(root->data > key) {
        return SearchRecursive(root->left, key);
    }
    else if(root->data < key) {
        return SearchRecursive(root->right, key);
    }
    else{// root->data == key 
        return true;
    }
}

int main(){
    vector<int> arr = {5, 1, 3, 4, 2, 7};
    Node* root = nullptr;
    for(int i = 0; i < arr.size(); i++) {
        root = insert(root, arr[i]);
    }
    inOrder(root);
    cout << endl;
    bool a = SearchRecursive(root, 3);
    if(a) cout << "fount the element " << 7;
    else cout << "could not find the element " << 7;
    return 0;
}