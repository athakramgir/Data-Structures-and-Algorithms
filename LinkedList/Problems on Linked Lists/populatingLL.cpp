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

void displayLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = nullptr;
    Node* temp = nullptr;
    Node* tail = nullptr;
    int i = 1;
    int n = 0; 
    cout << "Enter the number of nodes "<< endl;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val = 0;
        cout << "Enter the value of " << i << " node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = tail->next;
    }
    displayLL(head);
    return 0;
}