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
void displayLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deleteNegativeNext(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        if(temp->data < 0) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            toDelete->next = nullptr;
            delete toDelete;
            
        }
        prev = temp;
        temp = temp->next;
    }
}
int main(){
    Node* head = nullptr; Node* tail = nullptr;
    int n = 0;
    cout << "Enter the size of the list" << endl;
    cin >> n;
    cout << "Enter the list" << endl;
    for(int i = 1; i <= n; i++) {
        int val;
        cout << "Enter the value for " << i << " node" << endl;
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
    deleteNegativeNext(head);
    displayLL(head);
    return 0; 
}