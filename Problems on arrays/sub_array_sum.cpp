#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter value of n " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k = 0;
    cout << "Enter the sum of sub-arrays" << endl;
    cin >>k;
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == k){
                count ++;
            }
        }
    }
    cout << "The total number of sub arrays is " << count;
    return 0;
}