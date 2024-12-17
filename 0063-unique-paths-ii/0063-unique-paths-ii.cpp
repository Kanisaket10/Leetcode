class Solution {
public:
    
    // Recursion
    int solve(int i, int j, vector<vector<int>>& obstacleGrid){
       if(i ==0 && j==0) return 1;
       if(i<0 || j<0) return 0;
       if(i>=0 && j>=0 && obstacleGrid[i][j] == 1) return 0;
       int up = solve(i-1, j, obstacleGrid);
       int left = solve(i, j-1, obstacleGrid);
       return up +left; 
    }
    // Memoisation
    int solve_memo(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]== 1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int up = solve_memo(i-1, j,obstacleGrid, dp);
        int left = solve_memo(i, j-1,obstacleGrid, dp);
        return dp[i][j] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       //Recursion call      return solve(m-1, n-1, obstacleGrid);
       
       //memoisation call
        // vector<vector<int>> dp(m,vector<int>(n, -1));
        // return solve_memo(m-1, n-1, obstacleGrid, dp);

        // Tabulation
        vector<vector<int>> dp(m,vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1) dp[i][j] =0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0, left=0;
                  if(i>0) up = dp[i-1][j];
                  if(j>0) left = dp[i][j-1];
                  dp[i][j]= up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};