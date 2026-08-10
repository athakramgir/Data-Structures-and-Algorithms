#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0 ;i < n; i++){
        cin >> arr[i];
    }


    int index = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            index = i;
            break;
        }

    }

    if(index == -1) {
        reverse(arr, arr + n);
    }
    for(int i = n - 1; i > index; i--) {
        if(arr[i] > arr[index]) {
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            break;
        }
    }
    reverse(arr + (index + 1), arr + n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}