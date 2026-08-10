#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

    }

    int k = 0;
    cout << "Enter k " << endl;
    cin >> k;
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    for(right = 0; right < n; right ++) {
        sum += arr[right];
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        
    }
    cout << "The longest subarray is of the size " << maxLen;
    return 0;
}