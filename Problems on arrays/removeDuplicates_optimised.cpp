#include<bits/stdc++.h>
using namespace std;



int remove_elements(int arr[], int *n, int var){
    int i = 0;
    for(int j = 1; j < *n; j++){
        if(arr[j] != var){
            swap(arr[j], arr[i]);
            i++;
        }
    }
    *n = i + 1;
    return i + 1;
}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "enter the element of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "Enter the number to be removed from the array "<< endl;
    int x = 0;
    cin >> x;
    int final = remove_elements(array, &n, x);
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "The size of the final array after removing the element is " << final;
    return 0;
}