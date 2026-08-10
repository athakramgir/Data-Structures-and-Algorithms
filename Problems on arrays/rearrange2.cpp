#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter the even n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the equal number of positives and negatives" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans(n, 0);
    int posI = 0, negI = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            ans[posI] = arr[i];
            posI += 2;
        }
        else {
            ans[negI] = arr[i];
            negI += 2;
        }
    }
    for(auto it: ans) {
        cout << it << " ";
    }
    return 0;
}