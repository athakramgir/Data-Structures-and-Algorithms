#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
    Node(int value, Node* ptr) {
        data = value;
        next = ptr;
    }
};

void traversal(Node* head) {
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

Node* deleteTail(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deleteHead(Node* head) {
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteK(Node* head, int k) {
    if(head == nullptr) return head;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        cnt += 1;
        if(cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        } 
        prev = temp;
        temp = temp->next;
        
    }
    return head;
}
Node* deleteVal(Node* head, int val) {
    if(head == nullptr) {
        return nullptr;
    }
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head->next;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* deleteMultiple(Node* head, int val) {
    while(head != nullptr && head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    if(head == nullptr) {
        return nullptr;
    }
    Node* temp = head->next;
    Node* prev = nullptr;
    while(temp != nullptr) {
        if(temp->data == val) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
Node* insertHead(Node* head, int X) {
    Node* newNode = new Node(X);
    newNode->next = head;
    head = newNode;
    return head;
}
Node* insertHead2(Node* head, int val) {
    return new Node(val, head);
}
Node* insertTail(Node* head, int val) {
    if(head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}
Node* insertAtK(Node* head, int val, int k) {
    Node* newNode = new Node(val);
    if(head == nullptr) {
        if(k == 1){
            return newNode;
        }
        else {
            return head;
        }
    }
    Node* temp = head;
    if(k == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    int cnt = 0;
    while(temp != nullptr) {
        cnt ++;
        if(cnt == k-1) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node* insertAtVal(Node* head, int val1, int val2){
// val1 is the value to insert before val2
    Node* newNode = new Node(val1);
    if(head == nullptr) {
        return nullptr;
    }
    if(head->data == val2){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        if(temp->data == val2) {
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* insertAtVal2(Node* head, int val1, int val2) {
    Node* newNode = new Node(val1);
    if(head == nullptr) {
        return nullptr;
    }
    
    if(head->data == val2) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        if(temp->next->data == val2) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node* reverseLL(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(temp != nullptr){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        
        // head = prev;
    }
    return prev;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(30);
    traversal(head);
    Node* newHead = reverseLL(head);
    traversal(newHead);
    return 0;
}