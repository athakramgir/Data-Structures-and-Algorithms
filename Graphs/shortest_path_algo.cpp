#include<bits/stdc++.h>
using namespace std;
/*-------------------------------Shortest path algo in directed graph with unit weights-----------------------*/
void dfs(int node, stack<int> &st, vector<pair<int, int>> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        int wt = it.second;
        if (!vis[v])
        {
            dfs(v, st, adj, vis);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int V, vector<vector<int>> &edges)
{
    // code here
    int N = edges.size();
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < N; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
    }
    stack<int> st;
    int src = 0;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, adj, vis);
        }
    }
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        int distance = dist[node];
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
/*-------------------------------Dijkstra's algo--------------------------------------------------------------*/
// Does not work on graphs with negative weights, because it will fall into an infinite loop as we add the distances (-ve) it will always go smaller and smaller. 
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int, int>>> adj(V); 
    for(auto &edge : edges) {
        int u = edge[0]; 
        int v = edge[1]; 
        int wt = edge[2]; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt}); 
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, src}); 
    vector<int> dist(V, INT_MAX); 
    dist[src] = 0; 
    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        int d = p.first; 
        int node = p.second; 
        for(auto &it : adj[node]) {
            int curr_wt = it.second;
            int curr_node = it.first; 
            if(curr_wt + d < dist[curr_node]) {
                dist[curr_node] = curr_wt + d; 
                pq.push({curr_wt + d, curr_node}); 
            }
        } 
    }
    return dist;
}
/*---------------------------------------Dijkstra's algorithm but with set------------------------------------*/
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src){
    vector<vector<pair<int, int>>> adj(V); 
    for(auto &edge : edges) {
        int u = edge[0]; 
        int v = edge[1]; 
        int wt = edge[2]; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt}); 
    }
    set<pair<int, int>> st; 
    vector<int> dist(V, INT_MAX); 
    st.insert({0, src}); 
    dist[src] = 0; 
    while(!st.empty()){ 
        auto it = *(st.begin()); 
        st.erase(st.begin()); 
        int d = it.first; 
        int node = it.second; 
        for(auto &i : adj[node]) {
            int curr_d = i.second;
            int curr_node = i.first; 
            if(curr_d + d < dist[curr_node]) {
                if(dist[curr_node] != INT_MAX) {
                    st.erase({dist[curr_node], curr_node}); 
                }
                dist[curr_node] = curr_d + d; 
                st.insert({curr_d + d, curr_node}); 
            }
        }
    }
    return dist; 
}
int main(){
    
    return 0;
}