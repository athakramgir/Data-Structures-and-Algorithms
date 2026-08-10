#include<bits/stdc++.h>
using namespace std;
/*--------------------------------Topological sorting of Directed Acyclic graph -----------------------------*/
void dfs(int node, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1; 
    for(auto& n : adj[node]) {
        if(!vis[n]) {
            dfs(n, st, vis, adj); 
        }
    }
    st.push(node); // push node into the stack
}
vector<int> topoSort(vector<vector<int>>& adj, int v){ 
    vector<int> vis(v, 0); 
    stack<int> st; 
    for(int i = 0; i <= v; i++) {
        if(!vis[i]) {
            dfs(i, st, vis, adj); 
        }
    }
    vector<int> topo_sorted; 
    while(!st.empty()) {
        topo_sorted.push_back(st.top()); 
        st.pop(); 
    }
    return topo_sorted; 
}

/*---------------------------*/
int main(){
    
    return 0;
}