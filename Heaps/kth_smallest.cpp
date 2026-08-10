#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min heap : for kth smallest element
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++) {
        if(pq.top() < arr[i]) { //pq.top() < arr[i] : the heap will store k largest elements. pq.top > arr[i] : the heap will store k smallest element
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }

}
int main(){
    int n = 0;
    cout << "Enter the value of n\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k = 0; 
    cout << "Enter the value of k\n";
    cin >> k;
    cout << "The sorted array is \n";
    
    // for(int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    cout << endl;
    int ans = kthSmallest(arr, n, k);
    cout << "The kth smallest element of the array is " << ans;

    return 0;
}