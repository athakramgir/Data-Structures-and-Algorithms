#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;

    cout << "Enter n  " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter 0s and 1s in the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int max_count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            count ++;
            max_count = max(count, max_count);
        }
        else{
            count = 0;
        }
    }
    cout << max_count;
    return 0;
}