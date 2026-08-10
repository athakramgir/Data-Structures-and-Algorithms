#include<bits/stdc++.h>
using namespace std;
// all the DFS take O(n)
class Node{
    public:
    int data;
    Node* left;
    Node* right; 
    Node(int val){
        data =val;
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
void PostOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
vector<int> iterativePostOrder(Node* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
    }
    while(!st2.empty()){
        Node* temp = st2.top();
        st2.pop();
        ans.push_back(temp->data);

    }
    return ans;
}

vector<int> postOrderUsingOneStacks(Node* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    Node* curr = root;
    Node* temp = nullptr;
    stack<Node*> st;
    while(curr != nullptr || !st.empty()){
        if(curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            temp = st.top()->right; st.pop();
            if(temp == nullptr) {
                temp = st.top();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top(); st.pop();
                    ans.push_back(temp->data);
                }
            } else { 
                curr = temp;
            }
        }
    }
    return ans;
}
void InOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
vector<int> Inorder(Node* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    while(curr != nullptr || !st.empty()){

        while(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        ans.push_back(curr->data);

        curr = curr->right;
    }
    return ans;
}
void PreOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);

}
vector<int> iterativePreOrder(Node* root){ 
    if(root == nullptr) return {};
    stack<Node*> st;
    st.push(root);
    vector<int> ans;
    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();

        ans.push_back(curr->data);
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
    return ans;
}

void LevelOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);// this is mainly to add a line break
    while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(curr == nullptr){
                cout << endl;// simply give a line break 
                if(q.empty()) {
                    break;
                } else{
                    q.push(nullptr);
                }
            } else {
                cout << curr->data << " ";
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);    
                }
            }  
    }
}

void MorrisTraversal(Node* root) {
    Node* curr = root; 
    Node* pre = nullptr; 
    while(!curr) {
        if(!curr->left) {
            cout << curr->left << " "; 
            curr = curr->right; 
        }
        else {
            pre = curr->left;
            while(pre->right && pre->right != curr) {
                pre = pre->right; 
            } 
            if(pre->right == nullptr) {
                pre->right = curr; 
                curr = curr->left; 
            }
            else {
                pre->right = nullptr; 
                cout << curr->data << " "; 
                curr = curr->right;
            }
        }
    }
}
int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1,-1, 3, -1, 6, -1, -1};
    int index = 0; 
    Node* root = buildTree(nodes, index);
    PreOrder(root); 
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    LevelOrder(root);
    return 0;
}