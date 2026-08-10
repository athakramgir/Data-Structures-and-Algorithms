#include<bits/stdc++.h>
using namespace std;


class Stack{
    public:
    stack<pair<int, int>> st;
    void push(int val)  {
        if(st.empty()) {
            st.push({val, val});
        }
        else{
            st.push({val, min(val, st.top().second)});
        }
    }
    void getMin() {
        cout << st.top().second << endl;
    }
    void toP(){
        cout << st.top().first << endl;
    }
    void pop(){
        st.pop();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(50);
    st.getMin();
    st.pop();
    return 0;
}