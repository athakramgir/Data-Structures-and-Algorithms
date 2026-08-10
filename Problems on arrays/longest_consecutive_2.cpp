#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0 ;
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    sort(arr, arr + n);
    int longest = 1, count = 0, last_smaller = INT_MIN; 
    for(int i = 0; i < n; i++) {
        if(arr[i] - 1 == last_smaller) {
            count ++;
            last_smaller = arr[i];
        }
        else if(last_smaller != arr[i]) {
            count = 1;
            last_smaller = arr[i];
        }
        longest = max(count, longest);
    }
    cout << "The longest is " << longest;

    return 0;
}