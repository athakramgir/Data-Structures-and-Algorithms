#include<bits/stdc++.h>
using namespace std;
void sortt(int array[], int n) { 
    for(int i = 0 ; i < n; i++){
        int min = i;
        for(int j = i ; j < n; j++){
            if(array[min] > array[j]){
                min = array[j];
            }
        }
        swap(array[i], array[min]);
    }
}
int second_largest(int array[], int n){
    int second = 0;
    for(int  i = n - 2; i >= 0; i--){
        if(array[i] != array[n-1]){
            second = array[i];
            break;
        }
    }
    return second;
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sortt(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    int final = second_largest(arr, n);
    cout << "The second largest element of the array is " << final;
    return 0;
}