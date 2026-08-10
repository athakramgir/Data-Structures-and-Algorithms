#include<bits/stdc++.h>
using namespace std;
bool isPresent(int array[], int target, int n) {
    for(int i = 0; i < n; i++) {
        if(array[i] == target) {
            return true;
        }
        
    }
    return false;
}
int main(){
    int n = 0 ;
    cout << "Enter n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int longest = 1;
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        int count = 1;
        while(isPresent(arr, x + 1, n)){
            x += 1;
            count += 1;
        }
        longest = max(count, longest);
    }
    

    cout << "The longest consecutive subarray is " << longest << endl;
    return 0;
}