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

/*------------------------------Job Sequencing Problem -------------------------------------------------------------*/
/*-------------------Approach 1 (wrong) - Problem- A job with lesser deadline will be skipped if done consecutively-*/
static bool cmp(vector<int> a, vector<int> b) {
      return a[2] >= b[2]; 
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        sort(Jobs.begin(), Jobs.end(), cmp); 
        int time = 0; 
        int task = 0; 
        int profit = 0; 
        for(int i = 0; i < Jobs.size(); i++) {
            if(time < Jobs[i][1]) {
              time++; 
              task++; 
              profit = profit + Jobs[i][2]; 
            }
        }
        return {task, profit}; 
}
/*------------------Approach 2 (Using Visited array) ---------------------------------------------------------------*/

static bool cmp(vector<int> a, vector<int> b) {
    return a[2] > b[2]; 
}
vector<int> JobScheduling(vector<vector<int>>& Jobs) {
    sort(Jobs.begin(), Jobs.end(), cmp); 
    int profit = 0; 
    int cnt = 0 ;
    int max_deadline = -1; 
    for(int i = 0 ; i < Jobs.size(); i++) {
        max_deadline = max(max_deadline, Jobs[i][1]); 
    }
    vector<int> hash(max_deadline+1, -1);
    for(int i = 0; i < Jobs.size(); i++) {
        for(int j = Jobs[i][1]; j > 0; j--) {
            if(hash[j] == -1) {
                hash[j] = Jobs[i][0]; 
                cnt++; 
                profit = profit + Jobs[i][2]; 
                break; 
            }
        }
    } 
    return {cnt, profit}; 
}
/*------------------------------135 - Candy ------------------------------------------------------------------------*/
/*-------------------Appraoch 1 (Brute)-----------------------------------------------------------------------------*/
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int left[n]; 
    int right[n]; 
    left[0] = 1; right[n-1] = 1; 
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            left[i] = left[i-1] + 1;
        } else { 
            left[i] = 1; 
        }
    }
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]){
            right[i] = right[i+1] + 1;
        } else {
            right[i] = 1; 
        }
    }
    int sum = 0; 
    for(int i = 0; i < n; i++) {
        sum += max(left[i], right[i]); 
    }
    return sum; 
}// T(n) = O(3*n), S(N) = O(2*N); 
/*---------------------Approach 2 (better) -------------------------------------------------------------------------*/
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int left[n]; 
    left[0] = 1;; 
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            left[i] = left[i-1] + 1;
        } else { 
            left[i] = 1; 
        }
    }
    int curr = 1; 
    int right = 1; 
    int sum = max(1, left[n-1]); 
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]){
            curr = right + 1; 
            right = curr; 
        } else {
            curr = 1; 
            right = 1;  
        }
        sum = sum + max(left[i], curr); 
    }
    // int sum = 0; 
    // for(int i = 0; i < n; i++) {
    //     sum += max(left[i], right[i]); 
    // }
    return sum; 
}// T(n) = O(2*n) but still S(n) = O(n) 
/*-------------------Appraoch 3 - (Optimal)-------------------------------------------------------------------------*/
int candy(vector<int>& ratings) {
    int sum = 1; int i = 1; 
    int n = ratings.size(); 
    while(i < n) {
        if(ratings[i] == ratings[i-1]) {
            sum += 1; 
            i++; 
            continue;
        }
        int peak = 1; 
        while(i < n && ratings[i] > ratings[i-1]) {
            peak += 1; 
            sum += peak; 
            i++; 
        }
        int down = 1; 
        while(i < n && ratings[i] < ratings[i-1]) {
            sum += down; 
            down++; 
            i++; 
        }
        if(down > peak){
            sum += down - peak; 
        }
    }
    return sum ;
}// T(n) = O(n) , S(n) = O(1) 
/*------------------------------Leetcode 57 - Insert Interval ------------------------------------------------------*/
/*-------------------Approach 1 (Brute)-----------------------------------------------------------------------------*/
/*-------only valid approach - cannot be optimised----------*/
vector<vector<int>> insertInterval1(vector<vector<int>>& intervals, vector<int>& newInterval) { 
    vector<vector<int>> ans; 
    int n = intervals.size(); 
    int i = 0; 
    while(intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]); 
        i++; 
    }
    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]); 
        i++;  
    }
    ans.push_back(newInterval); 
    while(i < n){
        ans.push_back(intervals[i]); 
        i++; 
    }
    return ans; 
}
int main(){
    
    return 0;
}