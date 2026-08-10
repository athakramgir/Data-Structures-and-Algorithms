#include<bits/stdc++.h>
using namespace std;


vector<int> NextHotDay(vector<int>& temperatures){
    int n = temperatures.size(); 
    stack<int> st; 
    vector<int> ans(n, 0); 
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop(); 
        }
        if(!st.empty()) {
            ans[i] = st.top() - i; 
        }
        st.push(i); 
    }
    return ans; 
}
int main(){
    int n = 0; 
    cout << "Enter the size of the days \n";
    cin >> n;
    vector<int> temperature(n); 
    cout << "Enter the temperature of days \n";
    for(int i = 0; i < n; i++) {
        cin >> temperature[i];
    }
    vector<int> ans = NextHotDay(temperature);
    for(auto it : ans) {
        cout << it << " "; 
    }
    return 0;
}