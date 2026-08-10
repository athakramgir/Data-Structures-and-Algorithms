#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array  " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    map<int, int> hash;
    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(auto it: hash) {
        if(it.second > n/2){
            cout << "ans = " << it.first << " ";
        }
    }
    return 0;

}