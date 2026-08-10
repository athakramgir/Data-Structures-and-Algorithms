#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s){
    stack<string> st;
    int i = s.size() - 1;
    while(i >= 0) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string conv = t1 + t2 + s[i];
            st.push(conv);
        }i++;
    }return st.top();
}
int main(){
    
    return 0;
}