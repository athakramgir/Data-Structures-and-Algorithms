#include<bits/stdc++.h>
using namespace std;

void reverse_array(int array[], int n) {
    for(int i = 0; i < n/2; i++ ) {
        swap(array[i], array[n - i]);
    }
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array  " << endl;
    for(int i = 0; i < n; i++ ){
        cin >> arr[i];
    }

    int k = 0; 
    cout << "Enter k" << endl;
    cin >> k;
    k = k % n;
    reverse(arr, arr + n);
    reverse(arr, arr + k);
    reverse(arr+k, arr + n);

    for(int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    return 0;
}