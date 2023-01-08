
// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return false;
        return true;
    }
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> vis, int zero) {
        if(!check(row, col, grid) or grid[row][col]==-1) return 0;
        if(grid[row][col] == 2) return zero == -1;
        grid[row][col] = -1;
        zero--;
        int top = dfs(row-1, col, grid, vis, zero);
        int left = dfs(row, col-1, grid, vis, zero);
        int right = dfs(row, col+1, grid, vis, zero);
        int down = dfs(row+1, col, grid, vis, zero);
        grid[row][col] = 0;
        zero++;
        return top + right + left + down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> start;
        int n = grid.size();
        int m = grid[0].size();
        int zero = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1) {
                    start = {i, j};
                }
                else if(grid[i][j] == 0) zero++;
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(start.first, start.second, grid, vis, zero);
    }
};