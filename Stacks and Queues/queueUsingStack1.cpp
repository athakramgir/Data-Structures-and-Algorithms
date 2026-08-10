#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    stack<int> s1, s2;
    void push(int x) {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
    }
    void top(){
        cout << s1.top() << endl;
    }
};
int main(){
    Queue q;
    q.push(19);
    q.push(20);
    q.push(40);
    q.top();
    q.pop();
    q.top();
    q.pop();
    q.top();
    return 0;
}