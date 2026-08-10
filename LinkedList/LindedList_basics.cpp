#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertArrayToLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
void displayLL(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
} 

int lengthOfLL(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count ++;
        temp = temp->next;
    }
    return count;
}

bool searchElement(Node* head, int target) {
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node* head = convertArrayToLL(nums);
    displayLL(head);
    // int ans = lengthOfLL(head);
    // cout << ans;
    int target = 4;
    bool ans = searchElement(head, 5);
    cout << ans;
    return 0;
}