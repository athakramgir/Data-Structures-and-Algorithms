#include<bits/stdc++.h>
using namespace std;
/*--------------------------Prim's Algorithm to Find MST (Weights as well as edges)-----------------------*/
int spanningTree(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V); 
    for(auto edge : edges){
        int u = edge[0]; 
        int v = edge[1]; 
        int wt = edge[2]; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt});  
    }        
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;  
    pq.push({0, {0, -1}}); 
    vector<int> vis(V, 0); 
    vis[0] = 1; 
    vector<vector<int>> mst; 
    int sum = 0; 
    while(!pq.empty()) {
        int wt = pq.top().first; 
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop(); 
        if(!vis[node]){
            if(parent != -1) {
                mst.push_back({parent, node}); 
            }
            sum += wt; 
        }
        vis[node] = 1; 
        for(auto it : adj[node]){
            int adjNode = it.first; 
            int adjWt = it.second; 
            if(!vis[adjNode]) {
                pq.push({adjWt, {adjNode, node}}); 
            }
        }
    }
    return sum; 
}

/*---------------------------------Disjoint Set Union-----------------------------------------------------*/
/*
    Algo for Union(u, v)
        1. Find the root (ultimate parent) of u and v , say pu and pv
        2. Find the rank of pu and pv. 
        3. Always connect smaller rank to the larger rank. If equal, you can connect anyone to anyone. 
*/
class DisjointSet {
    vector<int> rank; 
    vector<int> parent;
public: 
    DisjointSet(int n){
        rank.resize(n+1, 0); // 1-based
        parent.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
        } 
    }    
    int findPar(int u) {
        if(u == parent[u]) {
            return u; 
        }
        return parent[u] = findPar(parent[u]); 
    }
    void unionByRank(int u, int v) {
        int pu = findPar(u); 
        int pv = findPar(v);
        if(pu == pv) return; // u, v belongs to the same component 
        if(rank[pu] == rank[pv]) {
            parent[pv] = pu; 
            rank[pu] ++; 
        }
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv; 
        }
        else {
            parent[pv] = pu; 
        }
    }
}; 
int main(){
    DisjointSet ds(7); 
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6); 
    ds.unionByRank(3, 7); 
    cout << ds.findPar(7) << endl; 
    // if 3 and 7 are in the same component or not
    if(ds.findPar(3) == ds.findPar(7)) cout << "3 and 7 belong to the same component" << endl; 
    else cout << "3 and 7 does NOT belong to the same component" << endl; 
    return 0;
}