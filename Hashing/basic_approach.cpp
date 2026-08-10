#include<bits/stdc++.h>
using namespace std;
// how many times does 2 appear in an array? 


int f(int array[], int number, int n){
    int counter = 0; 
    for(int i = 0; i < n ; i++){
        if(array[i] == number){
            counter += 1;
        }
    }
    return counter;
}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "The number of times 2 occurs in the array is " << f(array, 2, n) << endl ;
    return 0;
}