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

int main(){

    return 0;
}