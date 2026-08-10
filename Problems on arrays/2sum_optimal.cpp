#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n "<< endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int target = 0;
    cout << "Enter the target" << endl;
    cin >> target;

    int left = 0, right = n - 1;
    
    while(left < right) {
        int sum = arr[right] + arr[left];
        if(sum == target){
            
            cout << "[" << left << ", " << right << "]";
            break;
        }
        else if(sum < target) {
           left++ ;
        }
        else if(sum > target) {
            right--;
        }
    }

    return 0;
}