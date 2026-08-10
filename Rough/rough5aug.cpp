#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> nge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (st.empty())
            ans[i] = n;
        else
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> pge(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int sumSubarrayMax(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev = pge(arr);
    vector<int> next = nge(arr);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i - prev[i];
        int right = next[i] - i;
        total = (total + (left * right * 1LL * arr[i]) % MOD) % MOD;
    }
    return total;
}

int main()
{

    return 0;
}