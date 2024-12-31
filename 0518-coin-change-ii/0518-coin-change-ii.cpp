class Solution {
public:
    int ways(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0) return amount % coins[0] == 0;

        if(dp[ind][amount]!= -1) return dp[ind][amount];
        int not_take = ways(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount) take = ways(ind, amount-coins[ind], coins, dp);
        return dp[ind][amount] = take+ not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return ways(n-1, amount, coins, dp); 
    }
};