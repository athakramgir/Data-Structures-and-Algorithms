#include<bits/stdc++.h>
using namespace std;


void finding_duplicates(int array[], int *n){//call by reference enables us to change the origional variable. 
    set <int> st;
    for(int i = 0; i < *n; i++){
        st.insert(array[i]);
    }
    int index = 0; 
    for(auto it : st) {
        array[index] = it;
        index ++;
    }
    *n = index;
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
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    finding_duplicates(arr, &n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}