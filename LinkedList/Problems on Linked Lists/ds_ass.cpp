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
void printList(Node* head) {
    Node* temp = head;
    while(temp->next != head) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void breakIntoEqualHalves(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    Node* head2 = slow->next;
    temp->next = head2;
    slow->next = head;
    printList(head);
    printList(head2);
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int size;
    cout << "Enter the size of the list" << endl;
    cin >> size;
    for(int i = 1; i <= size; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    tail->next = head;
    printList(head);
    breakIntoEqualHalves(head);
    return 0;
}