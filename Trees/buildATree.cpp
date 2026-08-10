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
int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1,-1, 3, -1, 6, -1, -1};
    int index = 0; 
    Node* root = buildTree(nodes, index);
    cout << root->data << endl;
    return 0;
}