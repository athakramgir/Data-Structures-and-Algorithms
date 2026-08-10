#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    stack<int> s1, s2;
    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(!s2.empty()){
            s2.pop();
        }
        else{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }s2.pop();
        }
        
    }
    void top(){
        if(!s2.empty()) {
            cout << s2.top() << endl;
        }
        else{
            while(!s1.empty() ) {
                s2.push(s1.top());
                s1.pop();
            }
            cout << s2.top() << endl;;
        }
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