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
    Node* fast = head;
    Node* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* head) {
    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeTwoList(left , right);
}
int main(){
    Node* head1 = nullptr; Node* tail1 = nullptr;
    Node* head2 = nullptr; Node* tail2 = nullptr;

    cout << "Enter the first list" << endl;
    for(int i = 1; i <= 5; i++) {
        int val;
        cout << "Enter value for the " << i << " node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head1 == nullptr) {
            head1 = newNode;
            tail1 = newNode;
        }
        tail1->next = newNode;
        tail1 = tail1->next;
    }
    cout << "Enter the second list" << endl;
    for(int i = 1; i <= 2; i++) {
        int val;
        cout << "Enter value for the " << i << " node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head2 == nullptr) {
            head2 = newNode;
            tail2 = newNode;
        }
        tail2->next = newNode;
        tail2 = tail2->next;
    }
    displayList(head1);
    displayList(head2);
    Node* ans = mergeTwoList(head1, head2);
    displayList(ans);
    return 0;
}