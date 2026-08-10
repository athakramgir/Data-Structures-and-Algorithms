#include<bits/stdc++.h>
using namespace std;


vector<int> bfsOfGraph(int v, vector<int> adj[]) { 
    int vis[v] ={0}; 
    vis[0] = 1; 
    queue<int> q; 
    q.push(0);  
    vector<int> bfs; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 
        
        for(auto it: adj[node]) { 
            if(!vis[it]) { 
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}

vector<int> dfsOfGraph(int node, vector<int> adj[], int vis[], vector<int>& lis) {
    vis[node] = 1; 
    lis.push_back(node); 
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfsOfGraph(it, adj, vis, lis); 
        }
    } 
}

void convertingAdjMatToAdjLis(vector<vector<int>>& adjMat){
    int v = adjMat.size(); 
    vector<int> adj[v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(adjMat[i][j] == 1 && i != j) {
                adj[i].push_back(j); 
                adj[j].push_back(i); 
            }
        }
    }
    // adj is the adjacency list 
}
vector<int> iterativedfs(vector<int> adj[], int v) {
    int n = v; 
    vector<int> vis(n, 0); 
    vector<int> ans; 

    stack<int> stk; 
    stk.push(0);
    while(!stk.empty()) {
        int node = stk.top(); 
        stk.pop(); 
        if(vis[node] == 1) {
            continue;
        }
        vis[node] = 1; 
        ans.push_back(node); 
        int size = adj[node].size(); 
        for(int i = size - 1; i >= 0; i--) {
            int v = adj[node][i];
            if(!vis[v]) stk.push(v); 
        }
    }
    return ans; 

}

/*-----------Cycle detection in an undirected graph ----------------------*/ 
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(dfs(it, node, vis, adj)) {
                return true; 
            }
        }
        else if(it != parent) {
            return true; 
        }
    }   
    return false;
}
     


bool cycleDetection(vector<int> adj[], int v) {
    int vis[v] = {0}; 
    // return dfs(1, -1, vis, adj); this would have worked for a completely connected graph 
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj)){
                return true; 
            } 
        }
    }    
    return false; 
}

/*------------------------Cycle Detection Using BFS in Graphs -------------------------------------------------*/
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1; 
    queue<pair<int, int>> q; 
    q.push({src, -1}); 
    while(!q.empty()) {
        int node = q.front().first; 
        int parent = q.front().second; 
        q.pop(); 
        for(auto it : adj[node]) {
            if(!vis[it] ) {
                vis[it] = 1; 
                q.push({it, node});  
            } else if(parent != it){ 
                return true; 
            }
        }
    }
    return false; 
}
bool cycleDetectionBFS(vector<int> adj[], int v) {
    int vis[v] = {0}; 
    for(int i = 1 ; i <= v; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) {
                return true; 
            }
        }
    }
    return false; 
}
/*--------------------------------------------Cycle Detection in Directed Graph-------------------------------------*/
/*---T(n) = O(V + E) , S(n) = (2*N)---*/
bool dfs3(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1; 
    pathVis[node] = 1; 

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs3(it, adj, vis, pathVis)) {
                return true; 
            }
        }
        else if(pathVis[it]) {
            return true; 
        }
    }
    pathVis[node] = 0; 
    return false; 
}
bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    int pathVis[V] = {0}; 
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs3(i, adj, vis, pathVis)) {
                return true; 
            }
        }
    }
    return false; 
}
int main(){
    // int n, m; 
    // cin >> n >> m ; 
    // graph has been stored here T = O(n) in an adjacency matrix
    // S = O(n^2) 
    // int adj[n + 1][m + 1];
    // for(int i = 0; i < m; i++) {
    //     int u, v; 
    //     cin >> u >> v; 
    //     adj[u][v] = 1; // adj[u][v] = wt for weighted graphs 
    //     adj[v][u] = 1;    
    // }   second line optional for directed graph 

    int n, m; // this is adjacency list 
    cin >> n >> m; 
    vector<int> adj[n + 1]; 
    for(int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);// for a directed graph this line is skipped. Therefore, the SC reduces to O(E) from O(2E) ;
    }
    return 0;
}