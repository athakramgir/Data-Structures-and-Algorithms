#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout <<" Enter the element of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];

    }
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    // bubble sorting 
    for(int i = n - 1; i >= 0; i--){
        bool swapped = false;
        for(int j = 0; j <= i - 1; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
        // cout << " runs " << endl;
    }
    cout << "The array after sorting is " << endl;
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}