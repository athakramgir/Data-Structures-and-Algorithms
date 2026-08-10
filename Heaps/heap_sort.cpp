#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int size, int i) {
    int largest = i; 
    int right = 2*i + 1;
    int left = 2*i;
    if(left <= size && a[left] > a[largest]){ 
        largest = left;
    }// in 0 based indexing left < size and in 1 based indexing left <= size
    if(right <= size && a[right] > a[largest]) {
        largest = right;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, size, largest);
    }
}
void heapSort(int arr[], int n){// O(nlogn) 
    int t = n;
    while(t > 1) {
        swap(arr[1], arr[t]);
        t--;
        heapify(arr, t, 1);
    }
}
int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5; 
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
    cout << "Printing the array now \n";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, n);
    cout << "After Sorting\n";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}