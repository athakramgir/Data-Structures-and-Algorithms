#include<bits/stdc++.h>
using namespace std;


/*------------------------------------Shortest Path in a Binary Maze------------------------------------------*/
// the leetcode version is slightly different but the concept remains same. 
int shortestPathBinaryMatrix(vector<vector<int>> &grid, int src_x, int src_y, int dest_x, int dest_y)
// this is the gjg variation where question is slightly different, howeever concept remains the same
// Notice how we can use a normal queue over here, rather than a priority queue because there is no distance associated with the edges. 
{
    int n = grid.size();
    int m = grid[0].size();
    if(grid[src_x][src_y] == 0 || grid[dest_x][dest_y] == 0) return -1; 
    vector<vector<int>> dist(n, vector<int>(m, 1e9)); 
    queue<pair<pair<int, int>, int>> q; 
    q.push({{src_x, src_y}, 0}); 
    dist[src_x][src_y] = 0;
    int dx[] = {1, 0, -1, 0}; 
    int dy[] = {0, -1, 0, 1}; 
    while(!q.empty()) {
        auto& cell = q.front(); q.pop(); 
        int x = cell.first.first;
        int y = cell.first.second; 
        int distance = cell.second; 
        if(x == dest_x && y == dest_y) {
            return distance; 
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i]; 
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == 1e9 && grid[nx][ny] == 1) {
                dist[nx][ny] = distance + 1; 
                q.push({{nx, ny}, distance + 1}); 
            }
        }
    }
    return -1; 
}
int main(){
    
    return 0;
}