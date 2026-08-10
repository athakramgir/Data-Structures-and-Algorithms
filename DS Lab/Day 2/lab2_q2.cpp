#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Enter the order of the polynomial (N): ";
    cin >> N;

    int coefficients[N + 1]; 

    cout << "Enter " << N + 1 << " coefficients (from a0 to a" << N << "):\n";
    for (int i = 0; i <= N; i++) {
        cout << "a" << i << ": ";
        cin >> coefficients[i];
    }

    
    cout << "\nPolynomial: ";
    for (int i = 0; i <= N; i++) {
        if (coefficients[i] == 0)
            continue; 

        if (i != 0 && coefficients[i] > 0)
            cout << " + ";

        if (i == 0)
            cout << coefficients[i];
        else if (i == 1)
            cout << coefficients[i] << "x";
        else
            cout << coefficients[i] << "x^" << i;
    }

    cout << endl;
    return 0;
}
