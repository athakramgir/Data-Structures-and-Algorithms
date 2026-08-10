#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    queue<int> q;
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 1; i <= size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    void top(){
        cout << q.front() << endl;
    }
};
int main(){
    Stack st;
    st.push(5);
    st.push(10);
    st.push(43);
    st.top();
    st.pop();
    st.pop();
    st.top();
    return 0;
}