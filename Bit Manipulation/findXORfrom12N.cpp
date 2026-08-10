#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    cout << "Enter the value of n" << endl;
    cin >> n;
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        ans = ans^i;
    }
    cout << "The XOR of the numbers from 1 to N is " << ans;
    return 0;
}