#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    } 
};

Node* reverseLL(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
void traverse(Node* head) {
    Node* temp = head;
    while(temp != nullptr){
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
    head->next->next->next->next = new Node(50);
    traverse(head);
    Node* newHead = reverseLL(head);
    traverse(newHead);
    return 0;
}