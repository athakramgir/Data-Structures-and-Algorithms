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
class TreeInfo{
    public:
    int height;
    int diameter;
    TreeInfo(int h, int d) {
        height = h;
        diameter = d;
    }
};

TreeInfo* diameter2(Node* root) {
    if(root == nullptr) {
        return new TreeInfo(0, 0);
    }
    TreeInfo* left = diameter2(root->left);
    TreeInfo* right = diameter2(root->right);

    int myHeight = max(left->height, right->height) + 1;
    int diam1 = left->diameter;
    int diam2 = right->diameter;
    int diam3 = left->height + right->height + 1;
    int myDiam = max(max(diam1, diam2), diam3);

    TreeInfo* myInfo = new TreeInfo(myHeight, myDiam);
    return myInfo;
}
int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1,-1, 3, -1, 6, -1, -1};
    int index = 0; 
    Node* root = buildTree(nodes, index);
    TreeInfo* ans = diameter2(root);
    cout << ans->diameter << endl;
    return 0;
}