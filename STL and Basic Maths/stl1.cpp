#include<bits/stdc++.h>

using namespace std;

void ExplainPair(){
    pair<int, int> p = {1, 4};
    cout<< p.first << " " << p.second<< endl;
    
    pair<int, pair<int, int>> q = {1, {2, 3}};
    cout<< q.first << " " << q.second.first << " " << q.second.second << endl;

    pair<int, int> arr[] = {{1, 4}, {2, 5}, {3, 6}};
    cout << arr[0].first << " " << arr[1].first << " " <<  arr[2].first << endl;
}
void explainVector(){
    vector<int> v; // this creates an empty container

    v.push_back(10);// 1 is inserted in the container(vector)
    v.emplace_back(20);// similar to push_back : dynamically increases size and pushes 2 in it. Faster than push_back.
    v.emplace_back(30);
    v.emplace_back(40);
    v.emplace_back(50);
    v.emplace_back(60);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});// use of curly braces
    vec.emplace_back(1, 2);// automatically assumes a pair

    vector<int> arb(5, 100);
    // a vector containing 5 elements each being 100.
    // vector<int> vec(5);
    // To access elements 
    cout << arb[0] << " " << arb.at(0) << endl;

    vector<int> v1(5, 20);
    vector<int> v2(v1);

    vector<int> :: iterator it = arb.begin();//v.begin() points to the first element
    it++;// now the second element 
    cout<< *(it) << endl;
    cout << arb.back()<< endl;

    // Printing the vector. 
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        // cout<< *it << endl;
    }
    // auto will automatically assign the data type 
    for(auto a = v.begin(); a != v.end(); a ++){
        cout<< *(a) << endl;
    }
    // for(int i = 0 ; i < 3; i++){
    //     cout << v.at(i) << endl;
    // }

    for(auto it : v){
        cout<< it << " ";
    }
    cout << endl;
    // erasing elements: .erase(iterator);
    // v.erase(v.begin() + 1); // the second element is erased;
    // erasing multiple elements 

    v.erase(v.begin() + 1, v.begin() + 3);
    for(auto it = v.begin(); it != v.end(); it++){
    cout<< *it << " ";
    }
    cout << endl;// {10, 40, 50, 60}
    v.insert(v.begin(), 300);// {300, 10, 40, 50, 60}
    v.insert(v.begin() + 1, 2, 35); //{300, 35, 35, 10, 40, 50, 60};
    for(auto it : v){
        cout << it << " ";
    }
    cout <<" - " << v.size() << " ";
    // v.clear(); erases all the elements of a vector
    cout << v.empty();

}
void explainList(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4); 

    ls.push_front(5);
    ls.emplace_front(8);
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout << *it << " ";
    }
    // insert() in vectors is very costly, push_front is very cheap compared to that. 
}
void explainDeque(){
    deque<int> dq;
    dq.push_back(5);
    dq.emplace_back(10);
    dq.push_front(15);
    dq.emplace_front(20);
    dq.pop_back();
    dq.pop_front();
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    cout << dq.back()<< endl;
    cout << dq.front() << endl;
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    }
}
void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.top()<< endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;

    stack<int> st1, st2; 
    st1.swap(st2);
    
}
void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.back() += 5; // 4 + 5 = 9;
    cout<< q.front()<< endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;

}
void explainPQ(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);
// data structure which keeps the largest element at the top. 
    cout<< pq.top()<< endl;
    pq.pop();

    cout << pq.top() << endl;
// minimum priority queue 
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(1);
    p.push(19);
    p.push(10);
    p.push(4);
    
    cout << p.top() << endl;
}
void explainSet(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.emplace(2);
    s.insert(3);
    s.insert(4);

    // auto it = s.find(3);// stores the address of 3
    auto it = s.find(6);// address of s.end()
    
    s.erase(5);

    int cnt = s.count(1); // gives the no of occurence of 1

    auto it1 = s.find(2);
    auto it2 = s.find(4);
    s.erase(it1, it2); // erase(start(), end());
    auto itu = s.lower_bound(2);
    auto iti = s.upper_bound(3);// works same as in vector
}
void explainMultiSet(){
    multiset<int> ms;
    ms.insert(1); // can have multiple occurences 
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); // erases all the occurences

    int cnt = ms.count(1);

    ms.erase(ms.find(1)); // erases a single occurence of 1
    // ms.erase(ms.find(1), ms.find(1)+2);

}
void explainUnorderedSet(){
    unordered_set<int> us;
    // similar to other set but upper_bound and lower_bound does not work
}
void explainMap(){
    map<int, int> m1;
    map<int , pair<int, int>> m2;
    map<pair<int, int>, int> m3;

    m1[1] = 2; 
    // m1.emplace({3, 1});
    m1.insert({3, 1});
    m1.insert({2,4});

    m3[{2, 3}] = 10;

    for(auto it : m1){
        cout<< it.first << " " << it.second << endl;
    }
    cout<< m1[1] << endl;
    cout << m1[5] << endl;

    auto it = m1.find(3);
    cout << (*it).second << endl; 
}
void explainMultiMap(){
    // same as map but duplicate keys 
}
void explainUnorderedMap(){
    // unique elements but not sorted 
}
bool comp(pair<int, int> p1, pair<int, int> p2){// are they in the correct order?
    if(p1.second < p2. second) return true;
    if(p1.second > p2.second) return false;// swap them 
    
    if(p1.first > p2.first) return true;
    if(p1.first < p2.first) return false;
}
void explainExtra()
{
    int n;
    int a[n];
    sort(a, a + n);

    vector<int> v;
    sort(v.begin(), v.end());

    // selective sort
    sort(a + 2, a + 4);

    // sort in descending order 
    // sort(a, a + n, greater<int>);

    pair<int, int> aa[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to the second element if 
    // second element is same, then sort according to
    //  first element but in descending

    // sort(a, a + n, comp); // self written comparitor 

    int num = 7; 
    int cnt = __builtin_popcount(num);// counts the number of set bits {1s};
    long long num1 = 1232235362365;
    int cnt2 = __builtin_popcountll(num1);

    // next_permutation 
    string s = "123";// to print all the permutations we start from the sorted version 
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
}

int main(){
    // explainExtra();
    string s = "123";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
    return 0;
}