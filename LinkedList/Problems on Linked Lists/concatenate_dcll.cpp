#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;;
    }
};

Node* concatenateDLL(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1->next != nullptr) {
        temp1 = temp1->next;
    }
    while(temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    temp1->next = head2;
    head2->prev = temp1;

    temp2->next = nullptr;
    return head1;

}
void display(Node* head){
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main(){
    int n = 0; 
    cout << "Enter the size of DLL " << endl;
    cin >> n;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    for(int i = 1; i <= n; i++) {
        int val = 0;
        cout << "Enter the value for " << i << "th node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head1 == nullptr) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            newNode->prev = tail1; 
            tail1 = tail1->next;
        }
    }
    cout << endl << "Enter the size of second DLL " << endl;
    int m = 0; 
    cin >> m; 
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    for(int i = 1; i <= m; i++) {
        int val = 0; 
        cout << "Enter the value of " << i << "th node" << endl;
        cin >> val;
        Node* newNode = new Node(val);
        if(head2 == nullptr) {
            head2 = newNode;
            tail2 = newNode;
        }
        else {
            tail2->next = newNode;
            newNode->prev = tail2;
            tail2 = tail2->next;
        }
    }
    display(head1);
    display(head2);
    concatenateDLL(head1, head2);
    display(head1);
    return 0;
}