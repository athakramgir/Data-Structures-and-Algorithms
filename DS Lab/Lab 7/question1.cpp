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
void displayList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node* merge(Node* left, Node* right) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(left != nullptr && right != nullptr) {
        if(left->data <= right->data) {
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
        
    }
    if(left != nullptr) {
        temp->next = left;
    }
    else{
        temp->next = right;
    }
    return dummyNode->next;
}
int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;
    cout << "Enter first linked list" << endl;
    for(int i = 1; i <= 5; i++) {
        int val; cin >> val;
        Node* newNode = new Node(val);
        if(head1 == nullptr){
            head1 = newNode;
            tail1 = newNode;
        }
        tail1->next = newNode;
        tail1 = tail1->next;
    }
    cout << "Enter second linked list" << endl;
    for(int i = 1; i <= 2; i++) {
        int val; cin >> val;
        Node* newNode = new Node(val);
        if(head2== nullptr){
            head2 = newNode;
            tail2 = newNode;
        }
        tail2->next = newNode;
        tail2 = tail2->next;
    }
    displayList(head1);
    displayList(head2);
    Node* newLL = merge(head1, head2);
    displayList(newLL);
    return 0;
}