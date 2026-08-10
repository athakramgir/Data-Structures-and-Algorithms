#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n " << endl;
    cin >> n;
    int matrix[n][n];
    cout << "Enter the elements of the matrix " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int ans[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout <<  ans[i][j] << " ";
        }cout << endl;
    }
    return 0;
}