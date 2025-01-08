class Solution {
public:
   
   // Memoization
    int solve(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>&dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy == 1){
            return dp[ind][buy] = max((-prices[ind]+ solve(ind+1, 0, n, prices, dp)), solve(ind+1, 1, n, prices, dp));
        }
        else{
            return dp[ind][buy] = max((prices[ind]+ solve(ind+1,1, n, prices, dp)), solve(ind+1, 0, n, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, n, prices, dp);

        // Tabulation
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        dp[n][1] = dp[n][0] = 0;

        for(int i=n-1; i>=0; i--){
            for(int b=0; b<=1; b++){
                if(b){
                    dp[i][b] = max((-prices[i]+dp[i+1][0]), dp[i+1][1]);
                }
                else{
                    dp[i][b] = max((prices[i]+dp[i+1][1]), dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
        
        //Space optimization
        vector<int> ahead(2, 0), cur(2, 0);
        
         for(int i=n-1; i>=0; i--){
            for(int b=0; b<=1; b++){
                if(b){
                    cur[b] = max((-prices[i]+ahead[0]), ahead[1]);
                }
                else{
                    cur[b] = max((prices[i]+ahead[1]), ahead[0]);
                }
            }
            ahead = cur;
        }
        return ahead[1];
        
    }
};