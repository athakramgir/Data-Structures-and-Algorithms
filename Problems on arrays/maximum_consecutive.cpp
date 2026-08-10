#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    // 
    map<int, int> hash;
    for(int i = 0; i < n; i++){ 
        hash[array[i]] ++;
    }

    int max = hash[0];
    for(auto it : hash) { 
        if(it.first > max) 
        {
            max = it.first;
        }
    }
    for(auto it : hash) { 
        cout << it.first << " " << it.second;
    }
    return 0;
}