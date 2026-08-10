#include<bits/stdc++.h>
using namespace std;


struct Node{ 
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
Node* ReverseLinkedList(Node* head){
    Node* prev = nullptr;
    Node* ahead = nullptr;
    Node* temp = head;
    while(temp != nullptr) {
        ahead = temp->next;
        temp->next = prev;
        ahead->next = temp;
        prev = temp;
        temp = temp->next;
    }
    return prev;
}
void traversal(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    traversal(head);
    Node* ans = ReverseLinkedList(head);
    traversal(ans);
    return 0;
}