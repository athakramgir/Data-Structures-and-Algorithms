#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n] ;
    cout << "Enter the elements of the array " << endl;
    for(int i = 0 ;i < n; i++) {
        cin >> arr[i];
    }

    int j = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }
    if(j != -1) {
        for(int i = j + 1; i < n; i++) {
            if(arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}