#include<bits/stdc++.h>
using namespace std;

vector<int> ngeOpt(vector<int>& arr) {  
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }       
    return ans;
}
vector<int> nge(vector<int> arr) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        bool inserted = false;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                ans.push_back(arr[j]);
                inserted = true;
                break;
            }
        }if(!inserted){
            ans.push_back(-1);
        }
    }
    return ans;
}
int main(){
    int n; 
    cout << "Enter the size of the array " << endl;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }cout << endl;
    vector<int> ans = ngeOpt(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}