#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;// max heap 
    
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "Element at top is " << pq.top() << endl;
    pq.pop(); 
    cout << pq.top();
    if(pq.empty()) {
        cout << "Pq is empty" << endl;
    } else {
        cout << "pq is not empty \n";
    }
    // min heap
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(4);
    mpq.push(5);
    mpq.push(6);
    mpq.push(2);
    cout << "Element at the top " << mpq.top() << endl;
    mpq.pop();
    cout << "second element is " << mpq.top() << endl;
    if(!mpq.empty()){
        cout << "Rishabh is gay " << endl;
    }
    cout << "The size of the heap is " << mpq.size() << endl;
    return 0;
}