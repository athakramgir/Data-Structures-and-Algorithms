#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack{
    int size;
    Node* top = nullptr;
    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    void pop(){
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    void top(){
        cout << top->data << endl;
    }
    void size(){
        cout << size << endl;
    }
};
int main(){
    
    return 0;
}