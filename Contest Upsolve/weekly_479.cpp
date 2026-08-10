#include<bits/stdc++.h>
using namespace std;

/*------------Question 1 - sort integers by binary reflection---------------*/
int reflect(int n) {
    string s = ""; 
    int x = n; 
    while(x) {
        if((x&1) == 1) {
            s += '1'; 
        }
        else {
            s += '0'; 
        }
        x >>= 1; 
    }
    int mul = 1; 
    int num = 0; 
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') {
            num = num + mul; 
        } 
        mul *= 2; 
    }
    return num; 
}
vector<int> sortByReflection(vector<int>& nums) {
    vector<pair<int, int>> ans; 
    for(auto it : nums) {
        ans.push_back({reflect(it), it}); 
    }
    sort(ans.begin(), ans.end(), [](auto& a, auto& b){
        if(a.first != b.first) return a.first < b.first; 
        return a.second < b.second; 
    });
    vector<int> ans2; 
    for(auto& it : ans) {
        ans2.push_back(it.second); 
    }
    return ans2; 
}

/*--------------Question 2 : Largest Prime number from consecutive prime sum----------------*/
bool isPrime(int num){
    if(num <= 1) return false; 
    for(int i = 2; i*i <= num; i++) {
        if(num%i == 0) return false; 
    }
    return true; 
}
int largestPrime(int n) {
    if(n <= 1) return 0; 
    if(n == 2) return 2; 
    vector<int> primes; 
    for(int i = n; i >= 2; i++) {
        if(isPrime(i)) {
            primes.push_back(i); 
        }
    }
} 
int main(){
    
    return 0;
}