#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> arr) {
    vector<int> st;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0) {
            st.push_back(arr[i]);
        }
        else{
            while(!st.empty() && st.back() > 0 && abs(arr[i]) > st.back()) {
                st.pop_back();
            } 
            if(!st.empty() && st.back() == abs(arr[i])) {
                st.pop_back();
            }
            else if(st.empty() || st.back() < 0) {
                st.push_back(arr[i]);
            }
        }

    } 
    return st;
}
int main(){
    int n = 0;  
    cout << "Enter the size of the array  " << endl;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }
    cout << "The origional series of asteroids is " << endl;
    for(int i = 0; i < array.size() ; i++) {
        cout << array[i] << " ";
    }cout << endl;
    vector<int> ans = asteroidCollision(array);
    cout << "After collision" << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}