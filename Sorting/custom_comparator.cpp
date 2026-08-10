#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; 
}
static bool cmp2(int a, int b) {
    return a > b; 
}
int main(){
    int n; 
    cout << "Enter the size of the array " << endl; 
    cin >> n; 

    // vector<pair<int, int>> pair_array(n); 
    // for(int i = 0; i < n; i++) {
    //     cout << "Enter the first element of " << i << " pair" << endl; 
    //     cin >> pair_array[i].first;
    //     cout << "Enter the second element of " << i  << " pair" << endl; 
    //     cin >> pair_array[i].second; 
    // }

    // for(int i = 0; i < n; i++) {
    //     cout << "The first element of " << i << " pair is " << pair_array[i].first << endl; 
    //     cout << "The second element of " << i << " pair is " << pair_array[i].second << endl << endl; 
    // }
    // cout << "After sorting by second element of each pair " << endl;
    // sort(pair_array.begin(), pair_array.end(), cmp); // Important
    // for(int i = 0; i < n; i++) {
    //     cout << "The first element of " << i << " pair is " << pair_array[i].first << endl; 
    //     cout << "The second element of " << i << " pair is " << pair_array[i].second << endl << endl; 
    // }
    vector<int> arr(n); 
    cout << "Enter the elements of the array \n"; 
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i]; 
    }
    cout << "Before sorting in decreasing order \n"; 
    for(int i = 0; i < n; i++) cout << arr[i] << " "; 
    cout << endl; 
    sort(arr.begin(), arr.end(), cmp2); 
    cout << "After sorting in decreasing order\n"; 
    for(int i = 0; i < n; i++) cout << arr[i] << " "; 
    return 0;
}