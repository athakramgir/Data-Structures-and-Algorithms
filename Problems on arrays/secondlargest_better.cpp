#include<bits/stdc++.h>
using namespace std;


int second_largest(int array[], int n) {
    int largest = array[0];
    // finding largest element - takes O(n)
    for(int i = 0; i < n; i++){
        if(array[i] > largest){
            largest = array[i];
        }
    }
    // finding second largest element takes O(n)
    int second = -1;
    for(int i = 0; i < n; i++){
        if(array[i] > second && array[i] != largest){
            second = array[i];
        }
    }
    return second;
}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;

    int arr[n];
    cout <<"enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int final = second_largest(arr, n);// takes O(2n)
    if(final == -1) cout << "There is no second element in the array" << endl;
    else cout << "The second largest element of the array is "<< final;
    return 0;
}