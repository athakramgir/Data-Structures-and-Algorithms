#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n, s, x;
        cin >> n >> s >> x;  
        vector<long long> arr(n); 
        long long sum = 0; 
        for(int i = 0; i < n; i++) {
            cin >> arr[i]; 
            sum += arr[i];    
        }

        long long difference = s - sum; 
        if(difference < 0) cout << "NO" << endl; 
        else if(difference >= 0 && difference%x == 0) cout << "YES" << endl; 
        else if(difference >= 0 && difference%x != 0) cout << "NO" << endl; 
    }
    return 0;
}