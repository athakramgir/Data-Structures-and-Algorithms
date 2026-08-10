#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the array elements " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    int hash[n + 1] = {0};
    for(int i = 0; i < n; i++){
        hash[array[i]] ++;
    }
    for(int i = 0; i < n; i++){
        if(hash[i] > 1) { 
            cout << "The duplicate element is " << i << endl;
        }
    }
    return 0;
}