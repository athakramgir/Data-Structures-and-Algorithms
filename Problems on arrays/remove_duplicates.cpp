#include<bits/stdc++.h>
using namespace std;


int remove_duplicates(int array[], int n){
    int i = 0; 
    for(int j = 1; j < n; j++){
        if(array[i] != array[j]){
            array[i + 1] = array[j];
            i++;
        }
    }
    return i + 1;
}
int main(){
    // given that the array is sorted
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int final = remove_duplicates(arr, n);
    cout << "The size of the array after removing duplicates is " << final << endl;
    // this means that the till size - 1 we will have unique elements, after that is not a bother
    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }
    return 0;
}