#include<bits/stdc++.h>
using namespace std;

int main(){
    int n  = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];

    }
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }cout << endl;
    int k = 0; 
    cout << "Enter the amount of places to be left rotated "<< endl;
    cin >> k;
    k = k % n; // means that after n rotations we will get the same array so we have to just rotate the REMAINDER TIMES. 
    // left rotate by k places
    int temp[n];
    for(int i = 0; i < k ; i++){ 
        temp[i] = array[i];
    }//storing first k elements in the temp
    for(int i = k; i < n; i++){
        array[i - k] = array[i];
    }// shifting each element to the left by k places

    for(int i = n - k; i < n; i++){
        array[i] = temp[i - (n - k)];
    }// putting the first k elements to the last after rotation 

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}