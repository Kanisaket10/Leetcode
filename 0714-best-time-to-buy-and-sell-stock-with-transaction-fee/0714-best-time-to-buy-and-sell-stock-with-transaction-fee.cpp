class Solution {
public:

    // Memoization
    int solve(int ind, int buy, int n,int fee, vector<int>&prices, vector<vector<int>>& dp){
        if(ind == n) return 0;
         
        if(dp[ind][buy]!=-1) return dp[ind][buy]; 
        if(buy) return dp[ind][buy] = max((-prices[ind]+solve(ind+1, 0, n,fee, prices, dp)), solve(ind+1, 1, n,fee, prices, dp));
        return dp[ind][buy] = max((prices[ind]+ solve(ind+1, 1, n,fee, prices, dp)-fee), solve(ind+1, 0, n,fee, prices, dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, n,fee, prices, dp);

        // Tabulation
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = 0, dp[n][1] = 0;

        for(int i=n-1; i>=0; i--){
            dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0]= max(prices[i]+dp[i+1][1] - fee, dp[i+1][0]);
        }
        return dp[0][1];
    }
};