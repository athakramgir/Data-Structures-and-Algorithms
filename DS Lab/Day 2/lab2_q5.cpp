#include <iostream>
using namespace std;

int main() {
    int M, N;
    
    cin >> M;
    
    cin >> N;

    int MAT[M][N];
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> MAT[i][j];

    int I1, J1, I2, J2;
    
    cin >> I1 >> J1 >> I2 >> J2;

    int el1_row_major = MAT[I1][J1];
    int el2_row_major = MAT[I2][J2];
    int product_row_major = el1_row_major * el2_row_major;


    int linear_array[M * N];

    int idx = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            linear_array[idx++] = MAT[i][j];
        }
    }

    int index1_col_major = J1 * M + I1;
    int index2_col_major = J2 * M + I2;
    int el1_col_major = linear_array[index1_col_major];
    int el2_col_major = linear_array[index2_col_major];
    int product_col_major = el1_col_major * el2_col_major;

    cout << el1_row_major << " x " << el2_row_major << " = " << product_row_major << endl;
    cout << el1_col_major << " x " << el2_col_major << " = " << product_col_major << endl;

    return 0;
}
