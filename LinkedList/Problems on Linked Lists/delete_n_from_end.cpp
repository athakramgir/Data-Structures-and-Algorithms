#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

void displayLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
ListNode* removeNthFromEndBrute(ListNode* head, int n) {
    int cnt = 0;
    ListNode* temp = head;
    while(temp != nullptr) {
        cnt ++;
        temp = temp->next;
    }
    if(cnt == n) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    int res = cnt - n;
    temp = head;
    while(temp != nullptr){
        res--;
        if(res == 0) {
            break;
        }
        temp = temp->next;
    }
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}
ListNode* removeNthFromEndOptimised(ListNode* head, int n) {
        if(head == nullptr) {
            return head;
        }
        
        ListNode* fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        return head;
}
int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next =  new ListNode(50);
    displayLL(head);
    ListNode* ans = removeNthFromEndBrute(head, 2);
    displayLL(head);
    return 0;
}