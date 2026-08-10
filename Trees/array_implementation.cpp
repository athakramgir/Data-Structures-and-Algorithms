#include<bits/stdc++.h>
using namespace std;

class Tree{
    public: 
    vector<int> tree;
    int capacity; 
   
    Tree(int size){
        capacity = size;
    }
    void insert(int index, int value) {
        if(index >= capacity) return;
        tree[index] = value;
    }
    void print(){
        for(int i = 0; i < capacity; i++){
            if(tree[i] == -1) cout << "- ";
            else cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    
    return 0;
}