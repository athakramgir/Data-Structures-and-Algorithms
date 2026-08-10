#include<bits/stdc++.h>
using namespace std;


class Node{ 
    // doubly linked list;
    public:
    int data;
    Node* next ;
    Node* back;
    Node(int data1, Node* ptr1, Node* ptr2){
        data = data1;
        ptr1 = next;
        ptr2 = back;
    }
    Node(int data1) {
        data = data1;
        back = nullptr;
        next = nullptr;
    }
};


void traverse(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* arrtoDLL(vector<int> &arr, int n) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        temp->next = nullptr;
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* prev =  head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

Node* deleteTail(Node* head) {
    Node* temp = head;
    while(temp->next != nullptr) { 
        temp = temp->next;
    }
    Node* newTail = temp->back; 
    newTail->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

Node* deleteAtK(Node* head, int k) {
    if(head == nullptr) {
        return nullptr;
    }
    if(k == 1) {
        Node* prev = head;
        head = head->next;
        free(prev);
        return head;
    }
    
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        cnt++;
        
        if(cnt == k && temp->next != nullptr) {
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            temp->next = nullptr;
            temp->back = nullptr;
            free(temp);
        }
        else if(temp->next == nullptr) {
            temp->back->next = nullptr;
            temp->back = nullptr;
            free(temp);
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteK2(Node* head, int k) {
    if(head == nullptr) return nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        cnt ++;
        if(cnt == k){
             break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == nullptr && front == nullptr) {
        return nullptr;
    }
    else if(prev == nullptr) {
        Node* temp = head;
        head = head->next;
        head->back = nullptr;
        temp->next = nullptr;
        free(temp);
        return head;
    }
    else if(front == nullptr) {
        Node* temp = head;
        while(temp != nullptr) {
            temp = temp->next;
        }
        Node* newTail = temp->back;
        newTail->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return head;
    }
    else {
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    return head;
}

void DeleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == nullptr) {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    else {
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

}

Node* insertNodeBeforeHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    newNode->back = nullptr;

    head->back = newNode;
    return newNode;
}

Node* insertNodeBeforeTail(Node* head, int val) {
    if(head->next == nullptr) {
        return insertNodeBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val);
    newNode->next = tail;
    newNode->back = prev;
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeK(Node* head, int k, int val) {
    if(k == 1){
        return insertNodeBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt ++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val);
    prev->next = newNode;
    temp->back = newNode;
    newNode->next = temp;
    newNode->back = prev;
    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val);
    newNode->next = node;
    newNode->back = prev;
    prev->next = newNode;
    node->back = newNode;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    
    Node* head = arrtoDLL(arr, 5);
   
    traverse(head);
    // Node* newHead = insertBeforeK(head, 3, 100);
    // DeleteNode(head->next->next->next->next);// cannot put head here because this will alter the value of origional head;
    insertBeforeNode(head->next->next, 18);// does not change head;
    traverse(head);
    return 0;
}