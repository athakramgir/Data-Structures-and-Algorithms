
#include <bits/stdc++.h>
using namespace std;
/*-----------LeetCode 547 - Number of Provinces---------------*/
/*If I can figure out the number of starting points for each component.
1. we check in the vis array for the presence of 1st node. If not present, the dfs that node.
2. The number of time we do this is the answer, i.e, the number of time we have new starting node.

- Space Complexity - O(n) for stack space + O(n) for the visited array = O(2*n)
- Time Complexity - O(n) + O(v + 2*e); we are calling traversal for each node ->near about O(n)
O(n) is for the outer loop;
*/
void traversal(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    int n = adj.size();
    for (int j = 0; j < n; j++)
    {
        if (adj[node][j] == 1 && !vis[j])
        {
            traversal(j, adj, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        { // This condition will not be true for the connected nodes of 0(start)
            traversal(i, isConnected, vis);
            count++;
        }
    }
    return count;
}
/*-----Alternate--------*/
int numberOfProvinces(vector<vector<int>> &isConnected)
{
    vector<int> adjls[isConnected.size()];
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1 & i != j)
            {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }
    int v = isConnected.size();
    vector<int> vis(v, 0);
    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {

            // traversal(i, adjls, vis); // traversal can be modified according to the type of ds used to make graph
        }
    }
}
/*-----------------------------------------------LeetCode 994 - Rotten Oranges------------------------------------*/

/*--------Time complexity = O(m*n) + O(m*n*4) ~= O(m*n)  --------------------*/
/*--------Space complexity = O(m*n) queue + visited matrix */
int oranges(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    // {{x, y}, t}
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    int cntFresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
                cntFresh++;
        }
    }
    int time = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    int cnt = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    if (cnt != cntFresh)
    {
        return -1;
    } // we can either see by count or

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m ;j++) {
    //         if(vis[i][j] != 2 && grid[i][j] == 1) {
    //             return -1;
    //         }
    //     }
    // }
    return time;
}

/*-------------------------------------------LeetCode 733 - Flood Fill, Algorithm -------------------------------*/
// Appoach 1 - through DFS , T(n) = O(m*n), S(n) = O(4*m*n) ~= O(m*n)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    int start = image[sr][sc];
    if (start == color)
        return image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dr = row + drow[i];
            int dc = col + dcol[i];
            if (dr >= 0 && dr < n && dc >= 0 && dc > m && image[dr][dc] == start)
            {
                image[dr][dc] = color;
                q.push({dr, dc});
            }
        }
    }
    return image;
}
/*-----------Doing same question with DFS ------------*/
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int initial, int drow[], int dcol[])
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int dr = row + drow[i];
        int dc = col + dcol[i];
        if (dr >= 0 && dr < n && dc >= 0 && dc < m && image[dr][dc] == initial && ans[dr][dc] != newColor)
        {
            dfs(dr, dc, ans, image, newColor, initial, drow, dcol);
        }
    }
}
vector<vector<int>> floodFillDFS(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];
    vector<vector<int>> ans = image;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, color, initial, drow, dcol);
    return ans;
}

/*-----------------------------------------LeetCode 542 - 01 matrix --------------------------------------------------------*/
/*-----T(n) = O(m*n) S(N) = O(m*n + m*n + m*n)  ~= O(m*n)----------------------*/
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    if (mat.empty() || mat[0].empty())
    {
        return {};
    }
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int lev = q.front().second;
        q.pop();
        dist[x][y] = lev;
        for (int i = 0; i < 4; i++)
        {
            int dr = x + drow[i];
            int dc = y + dcol[i];
            if (dr >= 0 && dr < n && dc >= 0 && dc < m && !vis[dr][dc])
            {
                vis[dr][dc] = 1;
                q.push({{dr, dc}, lev + 1});
            }
        }
    }
    return dist;
}

/*---------------------------------------Leetcode 130 Surrounded Regions -------------------------------------------*/
/*-------*/
void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis)
{
    vis[x][y] = 1;
    int n = board.size();
    int m = board[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int dr = x + drow[i];
        int dc = y + dcol[i];
        if (dr >= 0 && dr < n && dc >= 0 && dc < m && !vis[dr][dc] && board[dr][dc] == 'O')
        {
            dfs(dr, dc, board, vis);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    if (board.empty() || board[0].empty())
    {
        return;
    }
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // traverse first and last rows
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && board[0][j] == 'O')
        {
            dfs(0, j, board, vis);
        }
        if (!vis[n - 1][j] && board[n - 1][j] == 'O')
        {
            dfs(n - 1, j, board, vis);
        }
    }
    // traverse first and last columns
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
        {
            dfs(i, 0, board, vis);
        }
        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, board, vis);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
            {
                vis[i][j] = 1;
                board[i][j] = 'X';
            }
        }
    }
}
/*----------------------------Leetcode 1020 Number of Enclaves -----------------------------------------*/
/* T(n) = O(n + n + 4*m*n) ~= O(m*n), S(n) = O(m*n)*/
int numEnclaves(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && grid[0][j])
        {
            vis[0][j] = 1;
            q.push({0, j});
        }
        if (!vis[n - 1][j] && grid[n - 1][j])
        {
            vis[n - 1][j] = 1;
            q.push({n - 1, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && grid[i][0])
        {
            vis[i][0] = 1;
            q.push({i, 0});
        }
        if (!vis[i][m - 1] && grid[i][m - 1])
        {
            vis[i][m - 1] = 1;
            q.push({i, m - 1});
        }
    }
    int rcount = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        rcount++;
        for (int i = 0; i < 4; i++)
        {
            int dr = x + drow[i];
            int dc = y + dcol[i];
            if (dr >= 0 && dr < n && dc >= 0 && dc < m && !vis[dr][dc] && grid[dr][dc])
            {
                vis[dr][dc] = 1;
                q.push({dr, dc});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !vis[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
/*----------------------------------------------LeetCode 127 - Word Ladder ----------------------------------------------------------*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q; 
    q.push({beginWord, 1}); 
    unordered_set<string> st(wordList.begin(), wordList.end()); 
    st.erase(beginWord); 
    while(!q.empty()) {
        string word = q.front().first; 
        int steps = q.front().second; 
        q.pop(); 
        if(word == endWord) {
            return steps; 
        }
        // This takes O(wordLength*26*N*log(N)) N is the number of words in the wordList 
        // S(N) = O(N) 
        for(int i = 0; i < word.size(); i++) {
            char org = word[i]; 
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch; 
                if(st.find(word) != st.end()) {
                    st.erase(word); 
                    q.push({word, steps + 1}); 
                }
            }
            word[i] = org; 
        }
    }
    return 0 ; 
}
/*-------------------------------------------LeetCode 785 Is the Graph Bipartite? -------------------------------------------------------*/
/*- Key Idea - a bipartite graph can be colored with only two colors--*/
/*------ T(n) = O(V + 2*E), S(n) = O(V)------*/
bool dfs(int node, int color, int colour[], vector<vector<int>>& adj) {
    colour[node] = color;
    for(auto it : adj[node]) {
        if(colour[it] == -1) {
            if(!dfs(it, !color, colour, adj)) {
                return false; 
            }
        }
        else if(colour[it] == color){
            return false; 
        }
    } 
    return true; 
}
bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size(); 
    int color[v];
    for(int i = 0; i < v; i++) {
        color[i] = -1; 
    } 
    for(int i = 0; i < v; i++) { 
        if(color[i] == -1) {
            if(dfs(i, 0, color, graph) == false) return false ;

        }
    }
    return true; 
}
int main()
{
    return 0;
}
