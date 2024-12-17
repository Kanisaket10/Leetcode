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
       //return solve_me(m-1, n-1, grid, dp);

       // Tabulation
    //    for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         if(i==0 && j==0) dp[i][j] = grid[i][j];
    //         else{
    //             int up =INT_MAX, left= INT_MAX;
    //             if(i>0) up = dp[i-1][j];
    //             if(j>0) left = dp[i][j-1];
    //             dp[i][j] = grid[i][j]+ min(up, left);
    //         }
    //     }
    //    }
    //    return dp[m-1][n-1];

       // Space Optimization
       vector<int> prev(n, INT_MAX);
       for(int i=0; i<m; i++){
        vector<int> curr(n, INT_MAX);
        for(int j=0; j<n; j++){
            if(i==0 && j==0) curr[j] = grid[i][j];
            else{
                 int up =INT_MAX, left= INT_MAX;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
               curr[j] = grid[i][j]+ min(up, left);
            } 
        }
        prev = curr;
       }
       return prev[n-1];
    }
};