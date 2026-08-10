#include<bits/stdc++.h>
using namespace std;
// this is brute force
int main(){
    int n = 0; 
    cout << "enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    int k;
    cout << "enter k " << endl;
    cin >> k;
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    for(int i = 0; i < k; i++) {
        cout << temp[i] << " ";
    }cout << endl;
    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for(int i = 0; i < k; i++ ) {
        arr[i] = temp[i];
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}