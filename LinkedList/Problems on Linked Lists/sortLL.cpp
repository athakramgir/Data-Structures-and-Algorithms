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

void convert(Node* head, vector<int> array){
    Node* temp = head;
    int i = 0;
    while(temp != nullptr) {
        temp->data = array[i];
        i++;
        temp = temp->next;
    }
}


Node* sortLLBrute(Node* head) {
    Node* temp = head;
    
    
    vector<int> arr;
    temp = head;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    convert(head, arr);
    return head;
}
void displayList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = new Node(50);
    head->next = new Node(30);
    head->next->next = new Node(40);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(20);
    displayList(head);
    sortLLBrute(head);
    displayList(head);
    return 0;
}