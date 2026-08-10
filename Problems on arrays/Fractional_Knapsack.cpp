#include<bits/stdc++.h>
using namespace std;
class Item { 
    public: 
        double val; 
        double weight; 
}; 

static bool comp(Item val1, Item val2) {
    return (val1.val/val1.weight) >= (val2.val/val2.weight); 
}
double fractional_Knapsack(vector<Item> arr, double weight) {
// what is greedy here? basically sorting the arr with respect to val/weight ratio and then picking the max ratio first is greedy 
    sort(arr.begin(), arr.end(), comp); 
    double totalVal = 0; 
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].weight < weight) {
            totalVal = totalVal + arr[i].val; 
        }
        else { 
            totalVal = totalVal + (arr[i].val/arr[i].weight)*weight; 
            break; 
        }
    }
    return totalVal;
}
int main(){
    
    return 0;
}