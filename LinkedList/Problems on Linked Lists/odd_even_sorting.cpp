#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
ListNode* oddEvenListOPt(ListNode* head) {
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;
    while(even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) {
            arr.push_back(temp->val);
        }
        temp = head->next;
        while(temp != nullptr && temp->next != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) {
            arr.push_back(temp->val);
        }
        int i = 0;
        temp = head;
        while(temp != nullptr) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
}

void displayList(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout  << "NULL" << endl;
}
int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next=  new ListNode(50);
    displayList(head);
    ListNode* ans = oddEvenListOPt(head);
    displayList(head);
    return 0;
}