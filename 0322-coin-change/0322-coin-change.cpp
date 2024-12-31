class Solution {
public:
// Mempization
    int f(int ind, int amt, vector<int>& coins, vector<vector<int>> & dp){
        if(ind == 0){
          if(amt % coins[ind] == 0) return amt/coins[ind];
          else return 1e9;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int not_take = 0 + f(ind-1, amt, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= amt){
            take = 1 + f(ind, amt-coins[ind], coins, dp); 
        }
       return dp[ind][amt]= min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
    //    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //    int ans = f(n-1, amount, coins, dp);
    //    if(ans >= 1e9) return -1;
    //    return ans;

       // Tabulation
    //    vector<vector<int>> dp(n, vector<int>(amount+1, 0));
    //    for(int T=0; T<=amount; T++){
    //     if(T % coins[0] == 0) dp[0][T] = T/coins[0];
    //     else dp[0][T] = 1e9;
    //    }

    //    for(int i=1; i<n; i++){
    //     for(int T = 0; T<= amount; T++){
    //         int not_take = 0+ dp[i-1][T];
    //         int take = INT_MAX;
    //         if(coins[i] <= T) take =1+ dp[i][T-coins[i]];
    //         dp[i][T] = min(take, not_take);
    //     }
    //    }
    //    if(dp[n-1][amount] >= 1e9) return -1;
    //    return dp[n-1][amount];

       // Space Optimization
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
       for(int T=0; T<=amount; T++){
        if(T % coins[0] == 0) prev[T] = T/coins[0];
        else prev[T] = 1e9;
       }

       for(int i=1; i<n; i++){
        for(int T = 0; T<= amount; T++){
            int not_take = 0+ prev[T];
            int take = INT_MAX;
            if(coins[i] <= T) take =1+ curr[T-coins[i]];
            curr[T] = min(take, not_take);
        }
        prev = curr;
       }
       if(prev[amount] >= 1e9) return -1;
       return prev[amount];
       
    }
};