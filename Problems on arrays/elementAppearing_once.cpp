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
// best approach
    // int xor1 = 0;
    // for(int i = 0 ; i < n; i++) {
    //     xor1 = xor1 ^arr[i];
    // }

    // cout << xor1 << endl;

// brute force 
    
    // for(int i = 0; i < n; i++){
    //     int count = 0;
    //     int num = arr[i];
    //     for(int j = 0; j < n; j++){
    //         if(arr[j] == num) {
    //             count ++;
    //         }
    //     }
    //     if(count == 1) {
    //         cout << num;
    //     }
    // }

// better
    int max = arr[0];
    for(int i = 0; i < n; i++ ){
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    int hash[max + 1] = {0};
    for(int i = 0 ; i < n; i++) {
        hash[arr[i]] ++;
    }

    for(int i = 0; i < n; i++) {
        if(hash[i] == 1) {
            cout << i;
        }
    }
     return 0;
}