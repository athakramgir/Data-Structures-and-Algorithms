#include<bits/stdc++.h>
using namespace std;
void extractionOfDigits(int N){
    while(N > 0){
        int last_digit = N % 10; 
        N /= 10;
        cout<< last_digit << " ";
    }
}
int countDigits(int n){
    if(n == 0){
        cout << "1" << " ";
    }
    int count = 0; 
    while(n != 0){
        n /= 10; 
        count ++; 
    }
    return count; 
}
int countDigits2(int n){
    int count = (int)(log10(n) + 1);
    return count;
}
int reverseNumber(int n){
    int reverse_number = 0; 
    while(n > 0){
        int last_digit = n % 10; 
        n /= 10;
        reverse_number = 10*reverse_number + last_digit;
    }
    return reverse_number;
}
bool checkPalindrome(int n){
    int rev = 0; 
    int origional = n;
    while (n > 0){
        int last = n % 10; 
        n /= 10;
        rev = rev * 10 + last;
    } 
    if(rev == origional) return true;
    else return false;
}
bool checkArmstrongNumber(int n){
    int dup = n; 
    int sum = 0;
    int count = 0;
    while(n != 0){
        int last1 = n % 10; 
        n /= 10;
        count ++; 
    }
    n = dup; 
    while(n != 0){
        int last = n % 10; 
        n /= 10; 
        sum = sum + pow(last, count);
    }
    if(sum == dup){
        return true;
    }
    else return false;
}
void printAllDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
}
void printAllDivisors1(int n){// optimisied
    vector<int> ls;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            // cout << i << " ";a
            ls.push_back(i);
            if(n/i != i){
                // cout << n/i << " ";
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(), ls.end());// a vector can be used to store the factors and can be sorted to get everything sorted fashion 
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout << *it << " ";
    }
}
bool checkPrime(int n){
    int count = 0; 
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            count ++;
            if(n/i != i){
                count ++;
            }
        }
    }
    if(count == 2) return true;
    else return false;
}
void gcd1(int n, int m){
    int gcd = 0;
    for(int i = 1 ; i < min(n, m); i++){
        if(n % i == 0 && m % i == 0){
            gcd = i; 
        }
    }// this iterates through each and every factor of the lesser number
    cout << gcd;
}
void gcd2(int n, int m){
    for(int i = min(n, m); i > 0; i--){
        if(n % i == 0 && m % i == 0) {
            cout << i; 
            break;
        }
    }
}
void gcd3EucliedianAlgo(int m, int n){
    while(m > 0 && n > 0){
        if(m > n) m = m % n;
        else n = n % m;
    }
    if(m == 0) cout << n; 
    else cout << m; 
}


int main(){
    // int ans = reverseNumber(7789);
    int n = 0; 
    // cin >> n;
    // bool ans = checkPrime(n);
    // cout << ans;
    // printAllDivisors1(n);
    gcd3EucliedianAlgo(9, 12);
    return 0;
}