class Solution {
public:
    // Recursion 
    int solve(int i, int j ,vector<vector<int>>& grid ){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        int up =  solve(i-1, j, grid);
        int left = solve(i, j-1, grid);
        return grid[i][j] + min(up, left);
    }
    // memoization
    int solve_me(int i, int j ,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int up =  solve_me(i-1, j, grid, dp);
        int left = solve_me(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       // return solve(m-1, n-1, grid);
       vector<vector<int>> dp(m, vector<int>(n, -1));
       return solve_me(m-1, n-1, grid, dp);
    }
};