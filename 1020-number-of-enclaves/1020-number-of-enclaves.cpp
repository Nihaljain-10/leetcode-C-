class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid){
  int m = grid.size();
  int n = grid[0].size();
  int count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        count++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (grid[i][0] == 1) {
      count -= dfs(grid, i, 0);
    }
    if (grid[i][n - 1] == 1) {
      count -= dfs(grid, i, n - 1);
    }
  }
  for (int j = 0; j < n; j++) {
    if (grid[0][j] == 1) {
      count -= dfs(grid, 0, j);
    }
    if (grid[m - 1][j] == 1) {
      count -= dfs(grid, m - 1, j);
    }
  }
  return count;
}

int dfs(vector<vector<int>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
    return 0;
  }
  grid[i][j] = 0;
  return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
}
    
};