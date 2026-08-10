#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long k;
    cout << "Enter k " << endl;
    cin >> k;
    map<long long, int> presummpp;
    long long sum = 0;
    int len = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == k) {
            len = max(len, i + 1);
        }
        int rem = sum - k;
        if(presummpp.find(rem) != presummpp.end()){
            int leng = i - presummpp[rem];
            len = max(leng, len);
        }
        // presummpp[sum] = i;// this should not be updated if the sum previously exists 
        if(presummpp.find(sum) == presummpp.end()){
            presummpp[sum] = i;
        }
    }
    cout << "The size of the longest subarray with sum k is " << len;
    return 0;
}