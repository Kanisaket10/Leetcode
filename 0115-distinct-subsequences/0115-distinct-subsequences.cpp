class Solution {
public:
    int f(int i, int j, string s, string t){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]) return f(i-1, j-1, s, t) + f(i-1, j, s, t);
        return f(i-1, j, s, t);
    }
    
    //Memoization
    int memo(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = memo(i-1, j-1, s, t, dp) + memo(i-1, j, s, t, dp);
        }
        return dp[i][j] =  memo(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
     // return f(n-1, m-1, s, t); 
      vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
      return memo(n, m, s, t, dp); 

      // Tabulation
    //   vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //   for(int i=0; i<=n; i++) dp[i][0] = 1;
    //   for(int j=0; j<=m; j++) dp[0][j] = 0;

    //   for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         if(s[i-1] == t[j-1]){
    //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    //         } 
    //         else dp[i][j] = dp[i-1][j];
    //     }
    //   }
    //   return dp[n][m];
    }
};