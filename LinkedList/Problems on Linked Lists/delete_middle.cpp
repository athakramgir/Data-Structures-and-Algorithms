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

Node* deleteMiddle(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    int n = 0;
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    }
    int res = n/2;
    temp = head;
    while(temp != nullptr) {
        res--;
        if(res == 0){
            break;
        }
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
}

Node* deleteMiddleOpt(Node* head){
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* prev = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
} 
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    displayList(head);
    Node* ans = deleteMiddleOpt(head);
    displayList(ans);
    return 0;
}