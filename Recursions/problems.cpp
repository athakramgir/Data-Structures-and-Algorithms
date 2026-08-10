#include<bits/stdc++.h>
using namespace std;
/*------------------------------LeetCode 45 - Jump Game II ---------------------------------------------------------*/
/*---------------------Appraoch 1 - Brute - Recursion - Try out all the cases and return the minimum one -----------*/
int func(int ind, int jumps, vector<int> nums) {
    if(ind >= nums.size()-1) {
        return jumps; 
    }
    int mini = INT_MAX; 
    for(int i = 1; i < nums.size(); i++) {
        mini = min(mini, func(ind + i, jumps+1, nums)); 
    }
    return mini; 
}
int jump(vector<int>& nums) {
    return func(0, 0, nums); 
}
/*---------------------Approach 2 - Best - Go for ranges using l and r pointers ------------------------------------*/
int jump(vector<int>& nums) {
    int jumps = 0; 
    int l = 0;
    int r = 0;
    while(r < nums.size()-1) {// you got to stop at n - 1
        int farthest = 0; 
        for(int i = l; i <= r; i++) {
            farthest = max(farthest, i + nums[i]); 
        }
        l = r + 1; 
        r = farthest; 
        jumps++; 
    }
    return jumps; 
}

/*------------------------------Minimum Number of platforms required -----------------------------------------------*/
/*---------------------Appraoch 1 - Brute --------------------------------------------------------------------------*/

int func(vector<int>& arrival, vector<int>& departure) {
    int maxi = 0; 
    int n = arrival.size(); 
    for(int i = 0; i < n; i++) {
        int cnt = 1; 
        for(int j = 0; j < n; j++) {
            if(i != j && arrival[j] < departure[i] && arrival[i] < departure[j]) {
                cnt ++; 
            }
        }
        maxi = max(maxi, cnt); 
    }
    return maxi; 
}   
/*---------------------Appraoch 2 - Best --------------------------------------------------------------------------*/
int func(vector<int>& arr, vector<int>& dep) { 
    int n = arr.size(); 
    int i = 0 ;
    int j = 0; 
    int cnt = 0; 
    int max_cnt = 0; 
    while(i < n)  {
        if(arr[i] <= dep[j]) {
            i++; 
            cnt++; 
        }
        else { 
            j++; 
            cnt--; 
        }
        max_cnt = max(max_cnt, cnt); 
    }
    return max_cnt; 
}
int main(){
    
    return 0;
}