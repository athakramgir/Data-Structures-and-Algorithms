#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostFix(string s) {
    int i = 0; 
    stack<char> st;
    string ans = "";
    int n = s.size();
    while(i < n) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string infix;
    cout << "Enter the infix expression" << endl;
    cin >> infix;
    string ans = infixToPostFix(infix);
    cout << ans;
    return 0;
}