#include<bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    Node* next;
    Node(int pos) {
        num = pos;
        next = nullptr;
    }
};

void displayLL(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->num << "->";
        temp = temp->next;
    }
    cout<< head->num << endl;
}

Node* Josephus(Node* head, int k) {
    
    Node* temp = head;
    while(temp->next != temp) {
        Node* prev = nullptr;
        for(int i = 1; i < k; i++) {
            prev = temp;
            temp = temp->next;
        }
        Node* toDelete = temp;
        temp = temp->next;
        prev->next= temp;
        toDelete->next = nullptr;
        delete toDelete;
    }
    return temp;
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;
    cout << "Enter the value of n " << endl;
    cin >> n;
    for(int i = 1; i <= n; i++){
        Node* newNode = new Node(i);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    displayLL(head);
    tail->next = head;
    Node* ans = Josephus(head, 3);
    cout << "The remaining last node is " << ans->num;
    return 0;
}