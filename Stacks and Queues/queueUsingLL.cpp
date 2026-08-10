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

class Queue{
    Node* start = nullptr;
    Node* end = nullptr;
    int size = 0;
    void push(int x) {
        Node* temp = new Node(x);
        if(start == nullptr) {
            start = temp;
            end = temp;
        }else{
            end->next = temp;
            end = end->next;
            size += 1;
        }
        
    }
    void pop(){
        if(start == nullptr) {
            cout << "Queue is empty " << endl;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }
    void top(){
        if(start == nullptr) { 
            cout << "Queue is empty " << endl;
        }
        else{
            cout << start->next << endl;
        }
    }
    void size(){
        cout << size << endl;
    }
};
int main(){
    
    return 0;
}