#include<bits/stdc++.h>
using namespace std;


/*-----------------Lower Bound ---------------------------------------------------------------*/
// Lower bound means the smallest index such that for a given value x, arr[lower_bound] >= x
// Can be implemented using Binary Search in a time of O(log(n)) 
int implementLowerBound(vector<int>& arr, int x) {
    int n = arr.size(); 
    int high = n-1; 
    int low = 0; 
    int ans = n; 
    int mid; 
    while(low <= high) {
        mid = low + (high-low)/2; 
        if(arr[mid] >= x) {
            ans = mid; 
            high = mid-1; 
        }
        else {
            low = mid+1; 
        }
    }
    return ans; 
}
int main(){
    
    return 0;
}