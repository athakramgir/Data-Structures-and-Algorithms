#include<bits/stdc++.h>
using namespace std;


struct Node{
    string name;
    Node* next;
    Node(string value) {
        name = value;
        next = nullptr;

    }
};

void traversal(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->name << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* insertAtHead(Node* head, string data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
} 

Node* insertAtTail(Node* head, string data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->next != nullptr){
        
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteHead(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while(temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    free(temp);
    return head;
}
int main(){
    Node* head = new Node("John");
    head->next = new Node("Alice");
    head->next->next = new Node("Maria");
    head->next->next->next = new Node("Zara");
    traversal(head);
    Node* NewHead = insertAtHead(head, "Tom");
    traversal(NewHead);
    Node* ans1 = insertAtTail(head, "Emma");
    traversal(NewHead);
    Node* newHead1 = deleteHead(NewHead);
    traversal(newHead1);
    Node* ans2 = deleteTail(newHead1);
    traversal(ans2);
    return 0;
}