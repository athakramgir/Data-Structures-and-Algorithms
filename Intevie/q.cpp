#include<bits/stdc++.h>
using namespace std;


class Node{ 
    public: 
    int data; 
    Node* next; 
    Node(int val) {
        data = val; 
        next = nullptr; 
    }
}; 

Node* reverseLL(Node* head) {
    if(head == nullptr) return nullptr; 
    Node* curr = nullptr; 
    Node* prev = nullptr; 
    Node* temp = head; 
    while(curr != head){
        curr = temp->next; 
        temp->next = prev; 
        prev = temp; 
        temp = curr; 
    }

    head->next = prev; 
    return prev; 
}

void display(Node* head) {
    Node* temp = head->next; 
    cout << head->data << " ";
    while(temp != head) {
        cout << temp->data << " "; 
        temp = temp->next; 
    } cout << endl; 
}
int main(){
    Node* head = new Node(1); 
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = head; 
    display(head); 
    head = reverseLL(head); 
    display(head); 
    return 0;
}