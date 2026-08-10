#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    int i = 0; 
    stack<string> st;
    int n = s.size();
    string conv;
    while(i < n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }
        else {
            string t1 = st.top();st.pop();
            string t2 = st.top();st.pop();
            conv = '(' + t1 + s[i] + t2 + ')';
            st.push(conv);
        }
        i++;
    }
    return st.top();
}
int main(){
    
    return 0;
}