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
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if(j != 0) {
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    // step 2 = substitute 0s to the elements of remaining matrix

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3 = substitute the rows and cols used to mark 
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";       
        }cout << endl;
    }
    return 0;
}
