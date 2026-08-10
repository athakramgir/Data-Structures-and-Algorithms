#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int> st;
    int mini = INT_MAX;
    public:
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else{
            if(val > mini) {
                st.push(val);
            }
            else{
                st.push(2*val - mini);
                mini = val;
            }
        }
    }
    void pop(){
        if(st.empty()) {
            return;//what the hell am i doing in ecell, huh? well I want to crack a software engineering role in a decent product based company like amazon, flipkart,
        }
        int x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2*mini - x;
        }
    }
    int top(){
        if(st.empty()) { 
            return -1;
        }
        int x = st.top();
        if(mini < x) {
            return x;
        }
        else{
            return mini;
        }
    }
    int getMin(){
        return mini;
    }
};
int main(){
    MinStack stk;
    stk.push(10);
    stk.push(20);
    stk.push(40);
    stk.push(50);
    cout << stk.getMin();
    return 0;
}