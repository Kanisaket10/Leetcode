class Solution {
public:
    // Memoization
    int f(int i, int j, string s, string s2, vector<vector<int>>& dp){
        if(i<0 || j<0 ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s2[j]) return dp[i][j] = 1+f(i-1 , j-1, s, s2, dp);
        return dp[i][j] = max(f(i-1, j, s, s2, dp), f(i, j-1, s, s2, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s.begin(), s.end());
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(n-1,n-1, s, s2, dp);

        // Tabulation
        vector<int> prev(n+1, 0), cur(n+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s2[j-1]) cur[j] =1+ prev[j-1]; //b/c 1-based indexing
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur; 
        }
        return prev[n];
    }
};