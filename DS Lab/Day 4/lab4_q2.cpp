#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of rows (M): ";
    cin >> m;
    cout << "Enter the number of columns (N): ";
    cin >> n;

    // Declare a 2D array to store the sparse matrix.
    // The size is m*n in case all elements are non-zero.
    int sparseMatrix[m * n][3];
    int nonZeroCount = 0;
    int originalMatrix[m][n];

    cout << "Enter the elements of the matrix (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> originalMatrix[i][j];
            // Store only non-zero elements in the 3-tuple format
            if (originalMatrix[i][j] != 0) {
                sparseMatrix[nonZeroCount][0] = i; // Store row
                sparseMatrix[nonZeroCount][1] = j; // Store column
                sparseMatrix[nonZeroCount][2] = originalMatrix[i][j]; // Store value
                nonZeroCount++;
            }
        }
    }

    // Display the array representation of the sparse matrix
    if (nonZeroCount == 0) {
        cout << "\nThe matrix is a zero matrix (no non-zero elements)." << endl;
    } else {
        cout << "\nSparse Matrix Representation (Row, Col, Val):" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Row\tCol\tVal" << endl;
        cout << "------------------------------------------" << endl;
        for (int i = 0; i < nonZeroCount; ++i) {
            cout << sparseMatrix[i][0] << "\t" << sparseMatrix[i][1] << "\t" << sparseMatrix[i][2] << endl;
        }
    }

    return 0;
}