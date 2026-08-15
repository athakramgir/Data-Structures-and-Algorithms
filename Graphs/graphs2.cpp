#include <bits/stdc++.h>
using namespace std;
/*--------------------------------Topological sorting of Directed Acyclic graph -----------------------------*/
void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto &n : adj[node])
    {
        if (!vis[n])
        {
            dfs(n, st, vis, adj);
        }
    }
    st.push(node); // push node into the stack
}
vector<int> topoSort(vector<vector<int>> &adj, int v)
{
    vector<int> vis(v, 0);
    stack<int> st;
    for (int i = 0; i <= v; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }
    vector<int> topo_sorted;

    while (!st.empty())
    {
        topo_sorted.push_back(st.top());
        st.pop();
    }
    return topo_sorted;
}

/*--------------------------------------Kahn's Algorithm ----------------------------------------------------*/
// the bfs version of toposort

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(V, 0);
    for (auto node : adj)
    {
        for (auto &neig : node)
        {
            indegree[neig]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}
/*------------------------------------------------------------------Cycle Detection-----------------------------------------------------*/
// a) using kahn's algorithm

bool canFinish(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> indeg(n, 0);
    for (auto &node : adj)
    {
        for (auto &ne : node)
        {
            indeg[ne]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &neighbor : adj[node])
        {
            indeg[neighbor]--;
            if (indeg[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] != 0)
        {
            return false;
        }
    }
    return true;
}

// b) Using DFS

bool cycleDetectDAG(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (cycleDetectDAG(neighbor, vis, pathVis, adj))
            {
                return true;
            }
        }
        else if (pathVis[neighbor])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(vector<vector<int>> &adj, int n)
{
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (cycleDetectDAG(i, vis, pathVis, adj))
            {
                return true;
            }
        }
    }
    return false;
}

/*-----------------------------------------Shortest path in a Directed Weighted Graph--------------------------------*/
// returning a distance array giving shortest distance of each node from src
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
int main()
{

    return 0;
}