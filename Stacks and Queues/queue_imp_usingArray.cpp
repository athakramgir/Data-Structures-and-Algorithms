#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    static const int size = 10;// as size is not a run-time constant | q[size] - here size needs to be constant and therefore the keyword static const
    int q[size];
    int currSize = 0;
    int start = -1, end = -1;
    void push(int a) {
        if(currSize == size) {
            cout << "queue is full " << endl;
        }
        if(currSize == 0) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        q[end] = a; currSize += 1;
    }
    void pop(){
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
        }
        int el = q[start];
        if(currSize == 1) {
            start = -1; end = -1;
        }
        else {
            start = (start + 1) % size;
            currSize -= 1;
        }
    }

    void top(){
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
        }
        cout << q[start];

    }
    void size(){
        cout << currSize;
    }
};
int main(){
    
    return 0;
}