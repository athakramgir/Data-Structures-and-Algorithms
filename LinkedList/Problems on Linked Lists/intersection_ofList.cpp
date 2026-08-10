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
    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
Node* commonNodeBrute(Node* headA, Node* headB) {
    map<Node*, int> mpp;
    Node* temp = headA;
    while(temp != nullptr) {
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = headB;
    while(temp != nullptr) {
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Node* commonNodeBetter(Node* headA, Node* headB) {
    Node* t1 = headA;
    Node* t2 = headB;
    int n1 = 0, n2 = 0;
    while(t1 != nullptr) {
        n1++;
        t1 = t1->next;
    }
    while(t2 != nullptr) {
        n2++;
        t2 = t2->next;
    }
    t1 = headA; t2 = headB;
    int d;
    if(n2 > n1) {
        d = n2 - n1;
        while(d != 0){
            d--;
            t2 = t2->next;
        }
        while(t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    else{
        d = n1 - n2;
        while(d != 0) {
            d--;
            t1 = t1->next;
        }
        while(t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
}

Node* commonNodeOpt(Node* headA, Node* headB) {
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    Node* t1 = headA;
    Node* t2 = headB;
    while(t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
        if(t1 == t2) {
            return t1;
        }
        if(t1 == nullptr){
            t1 = headB;
        }
        if(t2 == nullptr) {
            t2 = headA;
        }
    }
    return nullptr;
}
int main(){
    Node* head1 = new Node(3);
    head1->next = new Node(1);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(6);
    head1->next->next->next->next = new Node(2);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(5);
    head2->next->next->next->next = head1->next->next;

    displayLL(head1);
    displayLL(head2);

    Node* ans = commonNodeOpt(head1, head2);
    cout << ans->data << endl;
    return 0;
}