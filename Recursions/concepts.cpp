#include <bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, vector<int> &arr, int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();
    printF(ind + 1, ds, arr, n);
}

// Printing subsequences with sum k | what if we wanted a single subsequence (any one) we could add a flag but we won't do it this way | we also have one pattern regarding this one (after the function);
bool flag = false;
void printK(int i, int k, vector<int> &ds, vector<int> &arr, int sum, int n)
{
    if (i == n)
    { // base case
        if (sum == k && !flag)
        {                // single subsequence
            flag = true; // single subsequence
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    printK(i + 1, k, ds, arr, sum, n);
    ds.pop_back();
    sum -= arr[i];
    printK(i + 1, k, ds, arr, sum, n);
}
// here we will use a boolean function and return true if condition is satisfied | the way function is called in main will also change
bool printK2(int i, int k, vector<int> &ds, vector<int> &arr, int sum, int n)
{
    if (i == n)
    {
        if (sum == k)
        { // condition satisfied
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
            return false; // condition not satisfied
    }
    ds.push_back(arr[i]);
    sum += arr[i];
    if (printK2(i + 1, k, ds, arr, sum, n) == true)
    {
        return true;
    }
    ds.pop_back();
    sum -= arr[i];
    if (printK2(i + 1, k, ds, arr, sum, n))
    {
        return true;
    }
    return false;
}
// COUNTING SUBSEQUENCES WITH SUM K
int printK3(int i, int k, vector<int> &arr, int sum, int n)
{
    if (sum > k)
        return 0; // can be done if array contains only positives
    if (i == n)
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }
    sum += arr[i];
    int l = printK3(i + 1, k, arr, sum, n);
    sum -= arr[i];
    int r = printK3(i + 1, k, arr, sum, n);
    return l + r;
}
// POWER SET PROBLEM
void gen_subsequence(string s)
{
    for (int num = 0; num < 1 << s.size(); num++)
    {
        string substr = "";
        for (int i = 0; i < s.size(); i++)
        {

            if (num & (1 << i))
            {
                substr += s[i];
            }
        }
        cout << substr << endl;
    }
}

// N Queens Problem
// This is inefficient, because we are running three loops (O(n)) that too n times so O(n^3) we can optimise this by hashing
bool isSafe(int row, int col, vector<string> &board, int n)
{
    int rrow = row;
    int ccol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = rrow;
    col = ccol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = rrow;
    col = ccol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int cols, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (cols >= n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, cols, board, n))
        {
            board[row][cols] = 'Q';
            solve(cols + 1, board, ans, n);
            board[row][cols] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

// Optimised N queens; 

int main()
{
    int n = 0;
    // cout << "Enter the value of n" << endl;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i] ;
    // }

    // vector<int> ds;
    // // printF(0, ds, arr, n);
    // int k;
    // cout << "Enter the value of k" << endl;
    // cin >> k;
    // // printK2(0, k, ds, arr, 0, n);

    // int cnt = printK3(0, k, arr, 0, n);
    // cout << "The count of the subsequences is " << cnt << endl;
    string s;
    cin >> s;
    gen_subsequence(s);
    return 0;
}