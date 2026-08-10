#include<bits/stdc++.h>
using namespace std;

int functio(string s, int k) {
    int n = s.size(); 
    int l = 0; 
    int r = 0; 
    unordered_map<char, int> mpp; 
    int maxLen = 0; 
    while(r < n) {
        mpp[s[r]] ++; 
        while(mpp.size() > k) {
            mpp[s[l]]--; 
            if(!mpp[s[l]]){
                mpp.erase(s[l]); 
            }
            l++; 
        }
        maxLen = max(maxLen, r-l+1); 
        r++; 
    }   
    return maxLen; 
}
int main(){
    
    return 0;
}