#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter the value of n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k = 0; 
    cout << "Enter the value of k " << endl;
    cin >> k;

    unordered_map<int, int> mpp;
    // mpp[0] = 1;
    int presum = 0, count = 0;
    for(int i = 0; i < n; i++) {
        presum += arr[i];
        int remove = presum - k;
        count += mpp[remove];
        mpp[presum] += 1;
    } 
    cout << "The count of the sub-array with sum " << k << " is " << count;
    return 0;
}