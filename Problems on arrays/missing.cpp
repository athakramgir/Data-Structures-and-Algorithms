#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements containing [0 to n] numbers" << endl;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

// approach 1
    // sort(arr, arr + n);// O(n^2);
    // int found = 0;
    // for(int i = 0; i < n; i++) {
    //     if(arr[i] != i) {
    //         cout << "The missing element is " << i << " ";
    //         found = 1;
    //         break;
    //     } 
    // }
    // if(found == 0) {
    //     cout << n << " ";
//  } 
// approach 2
    // map<int, int> hash;
    // for(int i = 0; i < n; i++) {
    //     hash[arr[i]]++;
   
    // }

    // for(int i = 0; i < hash.size(); i++)  {
    //     if(hash[i] == 0) {
    //         cout << i << " ";
           
    //     }
    //     else{
    //         cout << n;
    //         break;
    //     }
    // }'

    int sumArray = n*(n + 1)/2;
    int sum = 0;
    for(int i = 0; i < n ; i++) {
        sum += arr[i];
    }
    cout << sumArray - sum;
    // int xor1 = 0;
    // int xor2 = 0;
    // for(int i = 0; i < n; i++) {
    //     xor1 ^= arr[i];
    //     xor2 ^= i;
    // }
    // xor2  ^= n;
    // int final = xor1 ^ xor2;
    // cout << final;
    return 0;
}   