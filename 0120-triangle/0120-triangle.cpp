class Solution {
public:
     //Recursion
     int solve(int i, int j, int n, vector<vector<int>>& triangle){
        if(i == n-1) return triangle[n-1][j];
        int down = triangle[i][j] + solve(i+1, j,n, triangle);
        int diag = triangle[i][j]+ solve(i+1, j+1,n, triangle);
        return min(down, diag);
     }
     //Memoization
     int memo(int i, int j, int n,vector<vector<int>>& triangle,  vector<vector<int>>& dp){
         if(i == n-1) return triangle[n-1][j];
         if(dp[i][j] !=-1) return dp[i][j];

        int down = triangle[i][j] + memo(i+1, j,n, triangle, dp);
        int diag = triangle[i][j]+ memo(i+1, j+1,n, triangle, dp);
        return dp[i][j] = min(down, diag);
     }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
      //  return solve(0, 0, n, triangle);
      vector<vector<int>> dp(n, vector<int>(n, -1));
      // return memo(0, 0, n, triangle, dp);

      // Tabulation
    //   for(int j=0; j<n; j++){
    //     dp[n-1][j] = triangle[n-1][j];
    //   }
    //   for(int i=n-2; i>=0; i--){
    //     for(int j=i; j>=0; j--){
    //         int down = triangle[i][j] + dp[i+1][j];
    //         int diag = triangle[i][j] + dp[i+1][j+1];
    //         dp[i][j] = min(down, diag);
    //     }
    //   }
    //   return dp[0][0];

      //Space Optimisation 
      vector<int> prev(n,0), curr(n,0);
      for(int j=0; j<n; j++){
        prev[j] = triangle[n-1][j];
      }

      for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
           int down = triangle[i][j] + prev[j];
           int diag = triangle[i][j] + prev[j+1];
           curr[j]= min(down, diag);
        }
        prev = curr;
      }
      return prev[0];
    }
};