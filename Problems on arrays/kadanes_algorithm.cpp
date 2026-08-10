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

    int sum = 0;
    int maxi = INT_MIN;
    int start = -1, ansStart = -1, ansEnd = -1;
    for(int i = 0; i < n; i++) {
        if(sum == 0) {
            start = i;
        }
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    cout << "The maximum sum of a sub-array is " << maxi << endl;
    cout << "The sub-array whose sum is largest is " << endl;
    for(int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}