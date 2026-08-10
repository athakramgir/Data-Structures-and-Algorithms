#include<bits/stdc++.h>
using namespace std;

string reverse(string s) {
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] == '(') {
            s[i] = ')';
        }
        else if(s[i] == ')' ) {
            s[i] = '(';
        }
        swap(s[i], s[s.size() - i - 1]);
    }
    
}
int priority(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    else return -1;
}
string infixToPrefix(string s) {
    reverse(s);
    int i = 0; 
    stack<int> st;
    string ans = "";
    while(i < s.length()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }else{
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }st.push(s[i]);
        }
        
        i++;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans);
    return ans;

}
int main(){
    
    return 0;
} 