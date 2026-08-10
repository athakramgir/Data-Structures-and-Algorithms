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

void displayList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* mergeTwoList(Node* left, Node* right) {
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
Node* findMiddle(Node* head){
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    return mergeTwoList(leftHead, rightHead);
}
int main(){
    Node* head = nullptr; Node* tail = nullptr;
    

    cout << "Enter the first list" << endl;
    for(int i = 1; i <= 5; i++) {
        int val;
        cout << "Enter value for the " << i << " node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        
    }
    
    displayList(head);
    Node* ans = mergeSort(head);
    displayList(ans);
    return 0;
}