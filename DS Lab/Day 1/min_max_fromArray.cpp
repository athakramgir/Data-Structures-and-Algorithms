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
    int max = array[0];
    int min = array[0]; 
    for(int i = 1; i < n; i++){
        if(array[i] > max){
            max = array[i];
        }
        else if(array[i] < min){
            min = array[i];
        }
    }
    cout << "The maximum of the array is " << max << endl;
    cout << "The minimum of the array is " << min;
    return 0;
}