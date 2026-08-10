#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int top1 = -1;
    int stk[10];
    public:
    void push(int a) {
        top1 = top1 + 1;
        stk[top1] = a; 
    }
    void pop(){
        if(top1 == -1) return;
        top1 = top1 - 1;
    }

    void top(){
        if(top1 == -1) cout << "Stack is empty" << endl;
        cout << stk[top1] << endl;
    }
    void size(){
        if(top1 == -1) cout << "Stack is empty" << endl;;
        cout << top1 + 1 << endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.push(40);
    st.top();
    return 0;
}