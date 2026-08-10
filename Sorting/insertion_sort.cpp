#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n; 
    int array[n];
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    // insertion sort
    for(int i = 0; i < n; i++){
        int j = i; 
        while(j > 0 && array[j - 1] > array[j]){
            swap(array[i], array[i - 1]);
            j--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}