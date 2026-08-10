#include<bits/stdc++.h>
using namespace std;

bool check_sorted (int array[], int n) {
     for(int i = 1; i < n; i++){
        if(array[i] >= array[i - 1]){}
        else 
        { 
           return false;
        }
    }
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n] ;
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i] ;
    }
    bool a = check_sorted(arr, n);
    if(a) cout << "Array is sorted ";
    else cout << "Array is not sorted";
    // checking
   
    return 0;
}