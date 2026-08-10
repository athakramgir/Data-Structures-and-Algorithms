#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cout << "Enter the number of rows and columns " << endl;
    cin >> n; 
    cin >> m;
    int matrix[n][m];
    cout << "Populate the matrix " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int rows[n] = {0};
    int columns[m] = {0};
    for(int i =0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j =0 ; j < m; j++) {
            if(rows[i] || columns[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;

    }

    return 0;
}