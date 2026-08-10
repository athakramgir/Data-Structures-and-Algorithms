#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }    
};
Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* ahead = nullptr;
    while(temp != nullptr){
        ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
    return prev;
}

void traverse(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool detectLoopBrute(Node* head) {
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}
bool detectLoopOpt(Node* head) {
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;
    while(temp != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

Node* returnStartingOfLoopBrute(Node* head) {
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}
Node* returnStartingOfLoopOpt(Node* head) {
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;
    while(temp != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}


int findLengthOfTheLoop(Node* head) {
    Node* temp = head;
    int timer = 1;
    
    map<Node*, int> mpp;
    while(temp != nullptr) {
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int findLengthOfLoopOPT(Node* head) {
    Node* slow = head;
    Node* fast = head;int count = 1;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow) {
            
            while(fast->next != slow){
                count ++;
                fast = fast->next;
            }
            return count;
        }
        
    }
    return 0;
}

bool checkPalindrome(Node* head) {
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr) {
        st.push(temp->data);
    }
    temp = head;
    while(temp != nullptr) {
        if(temp->data != st.top()){
            return false;
        }
        temp = temp->next;
        st.pop();
        if(st.empty())return true;
    }
    
    
}

bool checkPalindrome2(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr) {
        if(first->data != second->data) {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(10);
    
    cout << checkPalindrome2(head);
    return 0;
}