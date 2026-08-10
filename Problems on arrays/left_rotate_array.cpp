#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0 ;
    cout << "enter n" << endl;
    cin >> n;
    int array[n];
    cout << "enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }cout << endl;
    // left_rotate
    int temp = array[0];
    for(int i = 1; i < n; i++){
        array[i - 1] = array[i];
    }
    array[n - 1] = temp;

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}