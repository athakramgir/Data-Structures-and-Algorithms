#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n - i - 1; j++){
            if(array[i] > array[i + 1]){
                swap(array[i], array[i + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(array[i] == array[i + 1]){
            cout << array[i]; 
        }
    }
    return 0;
}