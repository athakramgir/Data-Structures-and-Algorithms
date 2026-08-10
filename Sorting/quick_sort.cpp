#include<bits/stdc++.h>
using namespace std;

int partionfinding(int array[], int low, int high) {
    int pivot = array[low];
    int i = low;
    int j = high;
    while(i < j ) {
        while(array[i] >= pivot && i <= high - 1) {// so that it does not cross the boundary
            i++;
        }
        while(array[i] < pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(array[i], array[j]);
        }
    }
    swap(array[low], array[j]);
    return j;
}
void qs(int array[], int low, int high) { 
    if(low < high) {
        int partition_index = partionfinding(array, low, high) ;
        qs(array, low, partition_index - 1);
        qs(array, partition_index + 1, high);
    }
}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout <<"Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    qs(array, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}