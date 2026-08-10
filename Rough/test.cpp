#include<bits/stdc++.h>
#include<numeric>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    while(t) {
        int n = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }int index = 0;
        for(int i = 0; i < n; i++){
            bool x = false;
            for(int j = 2; j <= a[i]; j++) {
                if(__gcd(a[i], j) == 1){
                    index = j;
                    x = true;
                    break;
                }
            }   
            if(x) break;  
        }
        if(index == 0) cout << "-1";
        else cout << index << endl;
        t--;
    }
}