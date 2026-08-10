#include<bits/stdc++.h>
using namespace std;


class Queue{
    int *arr;
    int size; 
    int capacity;
    int front; 
    int rear;

    void resize(){
        int newCapacity = capacity*2; 
        int *newArr = new int[newCapacity];
        for(int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i)%capacity];
        }
        delete[] arr;
        capacity = newCapacity;
        arr = newArr;
        front = 0; 
        rear = size;

    }
    public: 
    Queue(int s = 4) {
        capacity = 4; 
        arr = new int[capacity];
        front = 0; 
        size = 0; 
        rear = 0; 
    }
    ~Queue(){
        delete[] arr;
    }
    bool empty(){
        return size == 0; 
    }
    void push(int x) {
        if(size == capacity) {
            resize();
        }
        arr[rear] = x; 
        rear = (rear + 1) % capacity; 
        size ++;
    }
    void pop(){
        if(empty()) {
            return;
        }
        front = (front+1)%capacity;
        size--;
    }
    int peek()
    {
        if(empty()) {
            return -1;
        }
        return arr[front];
    }
    void display(){
        if(empty()) {
            cout << "Queue is empty \n";
        }
        else { 
            for(int i = 0; i < size; i++){
                cout << arr[(front + i) % capacity] << " ";
            }cout << endl;
        }
    }
};
int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    cout << q.empty() << endl;
    q.display();
    return 0;
}