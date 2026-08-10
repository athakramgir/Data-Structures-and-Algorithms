#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout << "Enter the number of rows " << endl;
    cin >> n;
    cout << "Enter the number of columns" << endl;
    cin >> m;

    int matrix[n][m];
    cout << "Enter the elements of the matrix" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
        cout << matrix[top][i] << " ";
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
        
    }
    
    return 0;
}