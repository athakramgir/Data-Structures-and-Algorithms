#include<bits/stdc++.h>
using namespace std;

void Reverse(int array[], int n){
    for(int i = 0; i < n/2; i++) {
        swap(array[i], array[n - i]);
    }
}
int main(){
    int n = 0;
    cout << "Enter n " << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++)  {
        cin >> array[i] ;
    }
    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }cout << endl;
    int k = 0;
    cout << "Enter k" << endl;
    cin >> k;
    reverse(array, array + k);
    reverse(array + k, array + n);
    reverse(array, array + n);
    

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
