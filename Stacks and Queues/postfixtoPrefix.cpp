#include<bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s) {
    stack<string> st;
    int i = 0; 
    while(i < s.size()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string conv = s[i] + t1 + t2;
            st.push(conv);
        }
        i++;
    }return st.top();
}
int main(){
    
    return 0;
}