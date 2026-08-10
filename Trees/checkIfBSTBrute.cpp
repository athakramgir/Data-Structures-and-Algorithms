#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int value) {
        val = value;
        right = nullptr;
        left = nullptr;
    }
};
void Traversal(TreeNode* root, vector<int>& vec) {
    if(root == nullptr) {
        return;
    }
    Traversal(root->left, vec);
    vec.push_back(root->val);
    Traversal(root->right, vec);
}
bool isValidBST(TreeNode* root) {
    vector<int> vec;
    Traversal(root, vec);
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i - 1] >= vec[i]) {
            return false;
        }
    }

    return true;
}

TreeNode* prevptr = nullptr;
bool isValidBST(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }
    if(!isValidBST(root->left)) return false;
        
    if(prevptr != nullptr && prevptr->val >= root->val) return false;

    prevptr = root;

    return isValidBST(root->right);
}
int main(){
    
    return 0;
}