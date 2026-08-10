#include<bits/stdc++.h>
using namespace std;

struct Node{
    int sem;
    string name;
    string branch;
    int scholar;
    Node* next;
    Node(int sem1, string name1, int sch, string branch_replace) {
        sem = sem1;
        name = name1;
        scholar = sch;
        branch = branch_replace; 
        next = nullptr;
    }
};

void display(Node* head){
    if(head == nullptr) {
        cout << "There is no element in the list " << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout << " [" << temp->scholar << ", "<< temp->branch << ", " << temp->name << ", "<< temp->sem << "] " << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = new Node(3, "Athak", 267, "CSE");
    head->next = new Node(1, "Rishabh", 237, "CSE");
    head->next->next = new Node(3, "Nandini", 134, "Civil");

    display(head);
    
    return 0;
}