#include<bits/stdc++.h>
using namespace std;
void mergeF(int array[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(array[left] <= array[right]){
            temp.push_back(array[left]);
            left ++;
        }
        else{
            temp.push_back(array[right]);
            right ++;
        }
    }
    while(left <= mid){
        temp.push_back(array[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(array[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        array[i] = temp[i - low];
    }
    
}

void mergeSort(int array[], int low, int high){
    if(low == high){ return;}
    int mid = (high + low)/2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    mergeF(array, low, mid, high);
}
int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int array[n];
    cout << "enter the elements of the array" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    mergeSort(array, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << array[i];
    }
    return 0;
}