#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1 = 0;
    int n2 = 0;
    cout << "Enter n1 and n2" << endl;
    cin >> n1;
    cin >> n2;
    int arr1[n1];
    int arr2[n2];

    cout << "Enter the elements in the first array " << endl;
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the elements in the second array " << endl;
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }


    set<int> st;
    for(int i = 0; i < n1; i++) {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++) {
        st.insert(arr2[i]);
    }

    int union_array[st.size()];
    int i = 0; 
    for(auto it: st) {
        union_array[i++] = it;
    }

    for(int i = 0; i < st.size(); i++ ){
        cout << union_array[i] << " ";
    }
    return 0;
}