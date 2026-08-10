#include<bits/stdc++.h>
using namespace std;

class Node{ 
    public:
    int data;
    Node* next;
    Node(int val ) {
        data = val;
        next = nullptr;
    }
};
void display(Node* head) {
    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    
    int size;
    cout << "Enter the size of the linked list " << endl;
    cin >> size;
    for(int i = 1; i <= size; i++) {
        int val = 0;
        cout << "Enter the data for " << i << " node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next  = newNode;
            tail = tail->next;
        }
    }
    display(head);
    return 0;
}