#include<bits/stdc++.h> 
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    cout << "Enter the elements " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= n - 2; i++){
        int min = i;
        for(int j = i; j <= n - 1; j++){
            if(array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[min], array[i]);
    }
    for(int i = 0; i < n ; i++){
        cout << array[i]  <<  " ";
    }
}