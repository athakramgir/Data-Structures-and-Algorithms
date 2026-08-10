#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n; 
        cin >> n; 
        vector<long long> arr(n); 
        for(int i = 0; i < n; i++) cin >> arr[i]; 

        for(int i = 0; i < n; i++) {
            int maxi = i; 
            for(int j = i + 1; j < n; j++) {
                if(arr[j] > arr[maxi]) {
                    maxi = j; 
                }
            }
            if(arr[maxi] > arr[i]) {
                reverse(arr.begin() + i, arr.begin() + maxi + 1); 
                break; 
            }
        }
        for(int i = 0; i < n; i++) cout << arr[i] << " "; 
        cout << endl; 
    }
    return 0;
}