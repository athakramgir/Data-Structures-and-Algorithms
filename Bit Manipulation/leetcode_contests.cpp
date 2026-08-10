#include<bits/stdc++.h>
using namespace std;

/*-------Q2.) Number of operations to make the nums[i] a palindrome in binary*/
bool isPalindrome(int num) {
    if(num < 1) return false; 
    if(num == 0 || num == 1) return true;
    string s = ""; 
    int x = num; 
    while(x) {
        if(x&1 == 1) s += "1"; 
        else s += "0";  
        x = x>>1; 
    }
    int i = 0; 
    int j = s.size() - 1; 
    while(i < j){
        if(s[i] != s[j]) {
            return false; 
        }
        i++; 
        j--; 
    }
    return true; 
}
/*-------------Q1.) Complete Prime number ----------------*/
bool chkPrime(long long num) {
    if(num <= 1) return false;
    if(num%2 == 0) return num == 2; 
    for(int i = 3; i*i <= num; i+=2) {
        if(num%i == 0) {
            return false; 
        }
    }
    return true; 
}
bool completePrime(int num) {
    if(!num) return false; 
    if(num == 1) return false; 
    if(!chkPrime(num)) return false; 
    long long x = num;
    vector<int> digits; 
    while(x) {
        int digit = x%10; 
        digits.push_back(digit); 
        x = x/10; 
    }
    reverse(digits.begin(), digits.end()); 
    long long y = 0;  
    for(int i = 0; i < digits.size() ; i++) {
        y = (y*10) + digits[i]; 
        if(!chkPrime(y)) return false; 
    }
    long long w = 0;
    long long mul = 1; 
    for(int i = digits.size() - 1; i >= 0; i--){
        w = w + digits[i]*mul; 
        if(!chkPrime(w)) return false;
        mul = mul*10; 
    }

    return true; 
}
vector<int> minOperations(vector<int>& nums) {
    int n = nums.size(); 
    vector<int> ans(n, 0); 
    for(int i = 0; i < n; i++) {
        int curr = nums[i]; 
        if(isPalindrome(curr)){
            ans[i] = 0; 
            continue; 
        } 
        int j = 1; 
        while(true){
            int left = curr - j;
            int right = curr + j; 
            if(left >= 0 && isPalindrome(left)){ 
                ans[i] = j; 
                break; 
            }
            if(isPalindrome(right)) {
                ans[i] = j; 
                break; 
            }
            j++; 
        }
        
    }
    return ans; 
}
int main(){
    
    return 0;
}