#include<bits/stdc++.h>
using namespace std;
struct Node{ 
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
    
};
void traverse(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
Node* brute(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        cnt ++;
        temp = temp->next;
    }
    int middle = cnt/2 + 1;
    temp = head;
    while(temp != nullptr) {
        middle --;
        if(middle == 0) {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* optimisted(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    Node* ans = optimisted(head);
    cout << ans->data;
    return 0;
}