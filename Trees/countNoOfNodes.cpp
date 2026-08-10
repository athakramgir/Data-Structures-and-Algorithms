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

int countNodes(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftNode = countNodes(root->left);
    int rightNode = countNodes(root->right);
    return leftNode + rightNode + 1;
}

int sumOfNode(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftSum = sumOfNode(root->left);
    int rightSum = sumOfNode(root->right);
    return leftSum + rightSum + root->data;
}
Node* buildTree(vector<int>& nodes, int& index) {
    if(index >= nodes.size() || nodes[index] == -1) {
        index ++;
        return nullptr;
    }
    Node* root = new Node(nodes[index]);
    index++;
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);

    return root;
}

int heightOfTree(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int LH = heightOfTree(root->left);
    int RH = heightOfTree(root->right);
    return max(LH, RH) + 1;
}

int diameter(Node* root){
    if(root == nullptr) {
        return 0; 
    }
    int diameter1 = diameter(root->left);
    int diameter2 = diameter(root->right);
    int diameter3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    return max(max(diameter1, diameter2), diameter3);
}
int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1,-1, 3, -1, 6, -1, -1};
    int index = 0; 
    Node* root = buildTree(nodes, index);
    cout << diameter(root) << endl;
    return 0;
}