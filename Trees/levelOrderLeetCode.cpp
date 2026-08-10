#include<bits/stdc++.h>
using namespace std;


class Node{ 
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    dfs(root, ans, 0);
    return ans;
}
void dfs(Node* root, vector<vector<int>>& ans, int level){
    if(root == nullptr) {
        return;
    }
    if(level == ans.size()) ans.push_back({});
    ans[level].push_back(root->data);
    if(root->left) dfs(root->left, ans, level + 1);
    if(root->right) dfs(root->right, ans, level + 1);
}
int main(){
    
    return 0;
}