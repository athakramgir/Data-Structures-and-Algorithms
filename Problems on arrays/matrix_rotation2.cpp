#include<bits/stdc++.h>
using namespace std;


int main(){
    int n = 0;
    cout << "Enter n" << endl;
    cin >> n;
    int matrix[n][n];
    cout << "Enter the elements of the matrix" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}