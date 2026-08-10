#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter the value of n \n";
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array \n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans;
    map<int, int> mpp;
    for(int i = 0 ; i < n; i++) {
        mpp[nums[i]]++;
    }

    for(auto it : mpp) {
        if(it.second == 1) {
            ans.push_back(it.first);
        }
    }
    for(auto it : ans) {
        cout << it << " ";
    }
    
    return 0;
}