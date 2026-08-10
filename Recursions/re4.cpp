#include<bits/stdc++.h>
using namespace std;
void reverseArray_using_loops(int array[], int n){
    for(int i = 0; i < n/2 ; i++){
        int temp = array[i];
        array[i] = array[4 - i];
        array[4 - i] = temp;
    }
}
void usingRecursion2pointer(int arr[], int n, int l, int r){
    if(l >= r) return ;
    else
    swap(arr[l], arr[r]);
    usingRecursion2pointer(arr, n, l + 1, r - 1);
}
void usingRecursion1pointer(int arr[], int n, int i){
    if(i > n / 2) return; 
    else 
    swap(arr[i], arr[n - 1 - i]);
    usingRecursion1pointer(arr, n, i + 1);
}
bool stringPalindrome(char arr[], int n, int i){
    if(i >= n/2) return true;
    else
        if(arr[i] != arr[n - i - 1]) return false;
        else return stringPalindrome(arr, n, i + 1);
}
int main(){
    int n = 0; 
    cin >> n;
    char s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    cout << stringPalindrome(s, n, 0);
    return 0;
}