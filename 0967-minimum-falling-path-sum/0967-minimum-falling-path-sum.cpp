class Solution {
public: 
    // Recursion
    int solve(int i, int j, int n, vector<vector<int>>& matrix){
        if(j<0 || j>= n) return INT_MAX;
        if(i == 0) return matrix[0][j];
        int dl = INT_MAX, dr = INT_MAX;
        int down =  solve(i-1, j, n, matrix);
        if(j>0)  dl = solve(i-1, j-1, n, matrix);
        if(j<n)  dr = solve(i-1, j+1, n, matrix);
        return matrix[i][j] + min(down, min(dl, dr));
    }
    // Memoization
    int memo(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp ){
        if(j<0 || j>=n) return INT_MAX;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
       
        int dl = INT_MAX, dr = INT_MAX;
        int down = memo(i-1, j, n, matrix, dp);
        if(j >0 ) dl = memo(i-1, j-1, n, matrix, dp); 
        if(j <n ) dl = memo(i-1, j+1, n, matrix, dp); 

        return dp[i][j] = matrix[i][j] + min(down, min(dl, dr));
    } 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
      //  vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int j=0; j<n; j++){
        // //   ans = min(ans, solve(n-1, j, n, matrix));
        //      ans = min(ans, memo(n-1, j, n, matrix, dp));
        // } 

      // Tabulation
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for(int j=0; j<n; j++){
        //     dp[0][j] = matrix[0][j];
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         int dl =INT_MAX, dr = INT_MAX;
        //         int down = dp[i-1][j];
        //         if(j-1>=0) dl = dp[i-1][j-1];
        //         if(j+1<n) dr = dp[i-1][j+1];
        //         dp[i][j] = matrix[i][j] + min(down, min(dl, dr));
        //     }
        // }
        //  for(int j=0; j<n; j++){
        //     ans = min(ans, dp[n-1][j]);
        // }  
       
       // Space Optimization
       vector<int> prev(n, 0), curr(n,0);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        
         for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int dl =INT_MAX, dr = INT_MAX;
                int down = prev[j];
                if(j-1>=0) dl = prev[j-1];
                if(j+1<n) dr = prev[j+1];
                curr[j] = matrix[i][j] + min(down, min(dl, dr));
            }
            prev = curr;
        }
        
        for(int j=0; j<n; j++){
            ans = min(ans, prev[j]);
        } 

       return ans;
    }
};