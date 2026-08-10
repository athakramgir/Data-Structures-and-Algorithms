#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int hash[25] = {0};
    // pre-computing
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    for(int i = 0; i< s.size(); i++){
        char ch;
        cin >> ch;
        // fetch 
        cout << hash[ch - 'a'] << endl;//here ascii values are considered so ch - 'a' gives the subtraction of ascii values, i.e, indexx
    }
    return 0;
}