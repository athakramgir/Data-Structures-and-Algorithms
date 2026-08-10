#include <iostream>
using namespace std;

// Global flag and arrays to store the result
bool subsetFound = false;
int resultSubset[100]; // Assuming max array size is 100
int resultSize = 0;

// Recursive function to find the subset
void findSubset(int arr[], int n, int m, int index, int currentSubset[], int currentSize) {
    // If a solution is already found, stop searching.
    if (subsetFound) {
        return;
    }

    // Calculate the sum of the current subset
    long long currentSum = 0;
    for (int i = 0; i < currentSize; ++i) {
        currentSum += currentSubset[i];
    }

    // Success condition: sum equals M
    if (currentSum == m && currentSize > 0) {
        subsetFound = true;
        resultSize = currentSize;
        for (int i = 0; i < currentSize; ++i) {
            resultSubset[i] = currentSubset[i];
        }
        return;
    }

    // Base case: if we've checked all elements, stop this path.
    if (index == n) {
        return;
    }

    // --- Recursive Step ---

    // 1. Recurse WITHOUT including the element at 'index'
    findSubset(arr, n, m, index + 1, currentSubset, currentSize);

    // 2. Recurse INCLUDING the element at 'index'
    currentSubset[currentSize] = arr[index];
    findSubset(arr, n, m, index + 1, currentSubset, currentSize + 1);
}

int main() {
    int n;
    cout << "Enter the size of the array (N): ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the positive integer M: ";
    cin >> m;

    int currentSubset[n];
    findSubset(arr, n, m, 0, currentSubset, 0);

    // Output the result
    if (subsetFound) {
        cout << "Subset with sum " << m << " found: { ";
        for (int i = 0; i < resultSize; ++i) {
            cout << resultSubset[i] << (i == resultSize - 1 ? "" : ", ");
        }
        cout << " }" << endl;
    } else {
        cout << "Output: -1" << endl;
    }

    return 0;
}