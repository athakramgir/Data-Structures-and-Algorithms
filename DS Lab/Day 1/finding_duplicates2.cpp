#include<bits/stdc++.h>
using namespace std;
// duplicates of an array containing 1 to n - 1 as elements
/// @return 
int main(){
    int n = 0; 
    cout << "Enter n" << endl;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }


    // finding duplicates
    int ans = 0; 
    for(int i = 0; i < n; i++){
        ans = ans^array[i];
    }
    for(int i = 1; i < n; i++){
        ans = ans^i;
    }
    cout << ans;
    return 0;
}