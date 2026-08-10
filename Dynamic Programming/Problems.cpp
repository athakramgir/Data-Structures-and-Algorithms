#include <bits/stdc++.h>
using namespace std;

/*---------------------------------Leetcode 198 House Robber -----------------------------------*/
// Recursion Method
int f(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    int pick = nums[index] + f(index - 2, nums);
    int not_pick = 0 + f(index - 1, nums);
    return max(pick, not_pick);
}
int rob(vector<int> &nums)
{
    return f(nums.size() - 1, nums);
}
// Memoization
int f(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
    {
        return nums[index];
    }
    if (index < 0)
        return 0;
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int pick = nums[index] + f(index - 2, nums, dp);
    int not_pick = 0 + f(index - 1, nums, dp);
    dp[index] = max(pick, not_pick);
    return max(pick, not_pick);
}

int rob2(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return f(nums.size() - 1, nums, dp);
}
// tabulation
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    vector<int> dp(n + 1, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int pick = nums[i] + dp[i - 2];
        int not_pick = dp[i - 1];
        dp[i] = max(pick, not_pick);
    }
    return dp[n - 1];
}
// space optimization
int rob4(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int prev2 = nums[0];
    int prev = nums[1];
    for (int i = 2; i < n; i++)
    {
        int pick = nums[i] + prev2;
        int not_pick = prev;
        int curr = max(pick, not_pick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
/*------------------------------------Unique Paths --------------------------------------------------------------*/
// Memoization.
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = f(i, j - 1, dp);
    int right = f(i - 1, j, dp);
    return dp[i][j] = left + right;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}
// Tabulation
int uniquePaths1(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
// Space Optimization

/*-----------------------------Leetcode 494 - Target Sum ---------------------------------------*/
// appraoch 1 - if we have to assign +, - we can assume that we have to divide the array into two subsets and their sum differnce will be equal to D where D is the target
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += nums[i];
    }
    int tar = (tsum - target) / 2;
    if (tsum - target < 0 || (tsum - target) % 2)
        return 0;
    vector<vector<int>> dp(n, vector<int>((tsum - target) / 2 + 1, -1));
    for (int T = 0; T <= tar; T++)
    {
        if (nums[0] == 0 && T == 0)
            dp[0][T] = 2;
        else if (T == 0 || nums[0] == T)
            dp[0][T] = 1;
        else
            dp[0][T] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= tar; T++)
        {
            int not_take = dp[i - 1][T];
            int take = 0;
            if (nums[i] <= T)
            {
                take = dp[i - 1][T - nums[i]];
            }
            dp[i][T] = (take + not_take);
        }
    }
    return dp[n - 1][tar];
}

// Approach 2 - Basic take, not take recursion --> memoization --> tabulation --> space optimizataion
int func(int ind, int sum, int target, int tsum, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == -1)
        return sum == target ? 1 : 0;
    if (dp[ind][sum + tsum] != -1)
        return dp[ind][sum + tsum];
    int plus = func(ind - 1, sum + nums[ind], target, tsum, nums, dp);
    int minus = func(ind - 1, sum - nums[ind], target, tsum, nums, dp);
    return dp[ind][sum + tsum] = plus + minus;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int tsum = 0;
    for (int i = 0; i < n; i++)
        tsum = tsum + nums[i];
    vector<vector<int>> dp(n, vector<int>(2 * tsum + 1, -1));
    return func(n - 1, 0, target, tsum, nums, dp);
}
// tabulation;
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += nums[i];
    }
    if (abs(target) > tsum)
        return 0;
    vector<vector<int>> dp(n, vector<int>(2 * tsum + 1, 0));
    dp[0][nums[0] + tsum] += 1;
    dp[0][-nums[0] + tsum] += 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = -tsum; sum <= tsum; sum++)
        {
            int ways = dp[ind - 1][sum + tsum];
            if (ways > 0)
            {
                dp[ind][sum + tsum + nums[ind]] += ways;
                dp[ind][sum + tsum - nums[ind]] += ways;
            }
        }
    }
    return dp[n - 1][target + tsum];
}
int main()
{

    return 0;
}