#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter n which should be even" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the negative elements and positive elements equally in even sized array " << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            neg.push_back(a[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            pos.push_back(a[i]);
        }
    }
    
    for(int i = 0; i < n/2; i++) {
        a[2*i] = pos[i];
        a[2*i + 1] = neg[i];
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}