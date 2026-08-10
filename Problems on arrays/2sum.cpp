#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }

    int target = 0;
    cout << "Enter the target" << endl;
    cin >> target;

    map<int, int> hash;
    for(int i = 0; i < n; i++) {
        int a = arr[i];
        int rem = target - a;
        if(hash.find(rem) != hash.end()){
            cout << "[" << hash[rem] <<", "<< i << "]";
        }
        hash[a] = i; 
    }
    return 0;
}