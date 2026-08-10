#include<bits/stdc++.h>
using namespace std;

void reverse(string s) {
    int n = s.size();
    for(int i = 0; i < n; i++) {
        swap(s[i], s[n - i - 1]);
    }
}

bool checkset(int n, int i) {
    if(n & (1<<i)) return true;
    else return false;
}
bool checkset2(int n, int i) {
    if((n>>i) & 1) return true;
    else return false;
}
string convert2binary(int n) {
    string ans;
    while(n != 1) {
        if(n % 2 == 1) {
            ans += "1";
        }
        else {
            ans += "0";
        }n = n/2;
    }
    ans += "1";
    reverse(ans);
    return ans;
}
int toggle(int n, int i ) {
    return (n ^ (1 << i));
}
int setith(int n, int i) {
    return (n | (1<<i));
}
int setithtozero(int n, int i) {
    return (n & ~(1 << i));
}
int convert2decimal(string binary) {
    int l = binary.size();
    int num = 0; 
    int powerof2 = 1;
    for(int i = l - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            num = num + powerof2;
        }
        powerof2 = powerof2*2;
    }
    return num;
}
int removeLastSetBit(int n) {
    return n & (n - 1);
}

int countSetBits(int n) {

    int counter = 0;
    while(n != 1) {
        if(n % 2 == 1) {
            counter ++;
        }
        n = n/2;
    }
    if(n == 1) counter ++;
    return counter; 
}
int countsetBits(int n) {
    int counter = 0;
    while(n != 1) {
        counter += n & 1;
        n = n >> 1;
    }
    if(n == 1) counter ++;
    return counter;
}
void oddoreven(int n) {
    if(n & 1) cout << "ODD";
    else cout << "EVEN";
}
int main(){
    // int n = 0;
    // cout << "Enter the number " << endl;
    // cin >> n;
    // cout << "The binary equivalent of the number is " << convert2binary(n); 
    // string binary = "11";
    // cout << "decimal equivalent " << convert2decimal(binary); 
    // cout << endl;
    // cout << ~5;
    oddoreven(2);
    return 0;
}