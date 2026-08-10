#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cout << "Enter n  " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i] ;
    }


    //
    int k = 0;
    cout << "Enter k " << endl;
    cin >> k;
    k = k % n;
    reverse(arr, arr + n);
    reverse(arr + k, arr + n);
    reverse(arr, arr + k);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}