#include<bits/stdc++.h>
using namespace std;


/*------------------------------------Shortest Path in a Binary Maze------------------------------------------*/
// the leetcode version is slightly different but the concept remains same. 
long long shortestPathBinaryMatrix(vector<vector<long long>> &grid, long long src_x, long long src_y, long long dest_x, long long dest_y)
// this is the gjg variation where question is slightly different, howeever concept remains the same
// Notice how we can use a normal queue over here, rather than a priority queue because there is no distance associated with the edges. 
{
    long long n = grid.size();
    long long m = grid[0].size();
    if(grid[src_x][src_y] == 0 || grid[dest_x][dest_y] == 0) return -1; 
    vector<vector<long long>> dist(n, vector<long long>(m, 1e9)); 
    queue<pair<pair<long long, long long>, long long>> q; 
    q.push({{src_x, src_y}, 0}); 
    dist[src_x][src_y] = 0;
    long long dx[] = {1, 0, -1, 0}; 
    long long dy[] = {0, -1, 0, 1}; 
    while(!q.empty()) {
        auto& cell = q.front(); q.pop(); 
        long long x = cell.first.first;
        long long y = cell.first.second; 
        long long distance = cell.second; 
        if(x == dest_x && y == dest_y) {
            return distance; 
        }
        for(long long i = 0; i < 4; i++) {
            long long nx = x + dx[i]; 
            long long ny = y + dy[i]; 
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == 1e9 && grid[nx][ny] == 1) {
                dist[nx][ny] = distance + 1; 
                q.push({{nx, ny}, distance + 1}); 
            }
        }
    }
    return -1; 
}

/*-------------------------------------------Number of Ways to Arrive at a Destination------------------------*/
// Finding out the number of shortest paths existing between src and dst. We can count the number of paths REACHING the dst with path_dist = shortest path , but that is WRONG. We also have to see the number of ways of reaching the penultimate level of nodes.
int countPaths(int n, vector<vector<int>>& roads) {
    const long MOD = 1e9 + 7; 
    int E = roads.size(); 
    int V = n; 
    vector<vector<pair<long long,long long>>> adj(V); 
    for(auto &it : roads) {
        long long u = it[0]; 
        long long v = it[1]; 
        long long wt = it[2]; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt}); 
    }
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>> ,greater<pair<long long,long long>>> pq; 
    vector<long long> dist(V, LLONG_MAX); 
    vector<long long> ways(V, 0); 
    long long src = 0; 
    long long dst = V-1; 
    dist[src] = 0; 
    ways[src] = 1; 
    pq.push({0, src}); 
    while(!pq.empty()) { 
        auto it = pq.top(); 
        pq.pop(); 
        long long node = it.second; 
        long long cur_dist = it.first; 
        for(auto iter: adj[node]) {
            long long adjNode = iter.second; 
            long long wt = iter.first; 
            if(wt + cur_dist == dist[adjNode]) {
                ways[adjNode] = (ways[node] + ways[adjNode])%MOD; // the number of ways previously counted + the number of ways there were for prev node 
            }
            else if(wt + cur_dist < dist[adjNode]) {
                dist[adjNode] = wt + cur_dist; 
                pq.push({wt + cur_dist, adjNode}); 
                ways[adjNode] = ways[node];
            }
        }
    }
    return ways[V-1]%MOD; 
}
/*---------------------------1368. Minimum Cost to Make at Least One Valid Path in a Grid----------------*/
const int INF = 1e9; 
int minCost(vector<vector<int>>& grid) {
    int m = grid.size(); 
    int n = grid[0].size(); 
    vector<vector<int>> dist(m, vector<int>(n, INF)); 
    dist[0][0] = 0; 
    deque<pair<int,int>> dq; 
    int dx[] = {INF, 0, 0, 1, -1}; 
    int dy[] = {INF, 1, -1, 0, 0}; 
    dq.push_front({0, 0}); 
    while(!dq.empty()) {
        auto node = dq.front(); dq.pop_front();    
        int x = node.first; 
        int y = node.second; 
        for(int i = 1; i <= 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i]; 
            if(nx >= 0 && nx < m && ny < n && ny >= 0) {
                int newCost = dist[x][y] + (grid[x][y] == i) ? 0 : 1; 
                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost; 
                    if(grid[x][y] == i) {
                        dq.push_front({nx, ny}); 
                    }
                    else {
                        dq.push_back({nx, ny}); 
                    }
                }
            }
        }
    }
    return dist[m-1][n-1]; 
}

long long main(){
    
    return 0;
}