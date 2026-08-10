#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter the value of n " << endl;
    cin >> n;

    vector<int> digits;
    while(n != 0) {
        int digit = n % 10;
        digits.push_back(digit);
        n/=10;
    }
    reverse(digits.begin(), digits.end());
    for(int i = 0; i < digits.size(); i++) {
        cout << i + 1 << "th digit is " << digits[i] << endl;
    }

    cout<<endl;
    return 0;
}