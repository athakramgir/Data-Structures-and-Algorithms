#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    // Node* newNode = new Node(arr[0]);
    Node newNode = Node(arr[1]);
    cout << newNode.next;
    return 0;
}