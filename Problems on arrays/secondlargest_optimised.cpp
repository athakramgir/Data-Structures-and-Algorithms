#include<bits/stdc++.h>
using namespace std;
int finding_secondSmallestElement(int array[], int n){
    int smallest = array[0];
    int secondSmallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(array[i] < smallest ){
            secondSmallest = smallest;
            smallest = array[i];
        }
        else if(array[i] != smallest && array[i] < secondSmallest) {
            secondSmallest = array[i];
        }
    }
    if(secondSmallest == INT_MAX) return -1;
    else return secondSmallest;
}
int second_largest(int array[], int n) {// the idea is that if largest element takes an element, the one it leaves becomes the second largest element
    int largest = array[0];
    int secondLargest = INT_MIN;// for all integers, but for positive we can take secondLargest = -1
    for(int i = 1; i < n; i++){
        if(array[i] > largest){
            secondLargest = largest;
            largest = array[i];
        }
        else if(array[i] < largest && array[i] > secondLargest){
            secondLargest = array[i];
        }
    }
    if(secondLargest == INT_MIN){// there is no second largest element
        return -1;
    }
    else {
        return secondLargest;
    }
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int final = finding_secondSmallestElement(arr, n);
    if(final == -1) cout << "There is no second smallest element in the array" << endl;
    else cout << "The second smallest element of the array is " << final;
    return 0;
}