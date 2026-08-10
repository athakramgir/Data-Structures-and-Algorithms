#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter the order of the matrix" << endl;
    cin >> n;
    int array[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            cin >> array[i][j];
        }
    }
    int sumd1 = 0, sumd2 = 0;
    for(int i = 0; i < n; i ++){
        sumd1 += array[i][i];
        sumd2 += array[i][n - i - 1];
    }

    int sumcol = 0, sumrow = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sumrow += array[i][j];
            sumcol += array[j][i];
        }
    }
    if(sumcol != sumrow && sumd1 != sumcol && sumd1 != sumd2){
        cout << "The matrix is not a magic matrix " << endl;
    }
    else {
        cout << "This is a magic matrix" << endl;
    }
    return 0;
}