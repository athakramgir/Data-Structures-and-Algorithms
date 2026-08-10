#include<bits/stdc++.h>
using namespace std;


bool magicMatrix(int array[][3], int n){
    int sumd1 = 0; 
    int sumd2 = 0; 
    for(int i = 0; i < n; i++){
        sumd1 += array[i][i];
        sumd2 += array[i][n - i - 1];
    }
    for(int i = 0; i < n; i++){
        int rowSum = 0; 
        int columnSum = 0;
        for(int j = 0; j < n; j++){
            rowSum += array[i][j];
            columnSum += array[j][i];
        }
        if(rowSum != columnSum || columnSum != sumd1){
            return false;
        }
    }
    return true;

}
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> array[i][j];
        }
    }
    
    if(magicMatrix) {
        cout << "The given matrix is a magic matrix ";
    }
    else {
        cout << "The given matrix is not a magic matrix ";
    }
    return 0;
}