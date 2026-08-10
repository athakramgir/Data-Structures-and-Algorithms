#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != index) {
        swap(arr[index], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
int main(){
    int n = 0; 
    cout << "Enter the value of n \n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}