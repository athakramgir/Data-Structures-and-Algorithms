#include<bits/stdc++.h>
using namespace std;

void sorting(int array[], int n) {
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        swap(array[min], array[i]);
    }
}
int binary_search(int array[], int start, int end, int target) {
    while(start <= end){
    int mid = start + (end - start) / 2;
        if(array[mid] == target) { 
        return mid;
    }
    if(array[mid] < target) {
        start = mid + 1;
    }
    else if(array[mid] > target) {
        end = mid - 1;
    }
    }
    return -1;
}


int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    // sort the array
    sorting(array, n);
    cout << "sorting the array first we get" << endl;
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }cout << endl;
    int x = 0; 
    cout << "Enter the target" << endl;
    cin >> x;
    int final = binary_search(array, 0, n - 1, x);
    if(final == -1) {cout << "Not present" << endl;}
    else {
        cout << "the index of the target is " << final;
    } 
    return 0;
}