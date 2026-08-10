#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++ ){
        cin >> arr[i];
    }

    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > maxi) {
            maxi = max(maxi, arr[i]);
            ans.push_back(arr[i]);
        }
    }
    
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}