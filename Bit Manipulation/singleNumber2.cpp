#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    int array[n];
    cout << "Enter the size of the array \n";
    cin >> n;
    cout << "Enter the elements of the array \n";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    long int xorr = 0;
    for(int i = 0; i < n; i++) {
        xorr = xorr^array[i];
    }
    int b1 = 0; 
    int b2 = 0; 
    int rightMost = (xorr & (xorr-1)) ^ xorr;
    for(int i = 0; i < n; i++) {
        if(rightMost & array[i]){
            b1 = b1 ^ array[i];
        }
        else {
            b2 = b2 ^ array[i];
        }
    }
    cout << b1 << " " << b2;
    return 0;
}