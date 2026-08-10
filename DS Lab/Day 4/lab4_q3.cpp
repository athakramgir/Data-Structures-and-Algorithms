#include<bits/stdc++.h>
using namespace std;

int FindPair(int array[], int n , int d) {
    int pairCount = 0;
    for(int i = 0 ; i < n; i++) {
        for(int j = i + 1; j < n ; j++) {
            if(abs(array[i] - array[j]) == d){
                pairCount++;
            }
        }
    }
    return pairCount;
}
int main(){
    int n = 0;
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int d = 0; 
    cout << "Enter D" << endl;
    cin >> d;

    int p = FindPair(arr, n, d);
    cout << "The number of such pair which have a sum of input d is " << p;
    return 0;
}