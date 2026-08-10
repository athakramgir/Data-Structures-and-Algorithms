#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* insertElementInSortedDLL(Node* head, int val) {
    Node* temp = head;
    Node* previous = new Node(-1);
    Node* newNode = new Node(val);
    while(temp != nullptr) {
        if(val > previous->data && val <= temp->data) {
            newNode->prev = previous;
            newNode->next = temp;
            previous->next = newNode;
            temp->prev = newNode;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}

void displayDLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;
    cout << "Enter size" << endl;
    cin >>n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
    displayDLL(head);
    Node* ans = insertElementInSortedDLL(head, 35);
    displayDLL(ans);
    return 0; 
}