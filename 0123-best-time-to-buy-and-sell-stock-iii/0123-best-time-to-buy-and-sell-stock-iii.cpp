class Solution {
public:
 
 // Memoization 
    int solve(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(ind == n || cap == 0) return 0;
        
        if(dp[ind][buy][cap] !=-1) return dp[ind][buy][cap];
        if(buy) return dp[ind][buy][cap] = max((-prices[ind] +solve(ind+1, 0, cap, n, prices, dp)),solve(ind+1, 1, cap, n, prices, dp));
        else return dp[ind][buy][cap] =max((prices[ind] + solve(ind+1, 1, cap-1, n, prices, dp)),solve(ind+1, 0, cap, n, prices, dp));
      
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, 2, n, prices, dp);

        // Tabulation
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
         
        //  for(int cap =0; cap<=2; cap++){
        //     dp[n][0][cap] = 0;
        //     dp[n][1][cap] = 0;
        //  }

        //  for(int ind =n-1; ind>=0; ind--){
        //     for(int buy=0; buy<=1; buy++){
        //         for(int cap=1; cap<=2; cap++){
        //             if(buy) dp[ind][buy][cap] = max((-prices[ind] +dp[ind+1][0][cap]),dp[ind+1][1][cap]);
        //             else dp[ind][buy][cap] = max((prices[ind] +dp[ind+1][1][cap-1]),dp[ind+1][0][cap]);
        //         }
        //     }
        //  }  
        // return dp[0][1][2];

        //Space optimization 2D-arry
        vector<vector<int>> after(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
         for(int cap =1; cap<=2; cap++){
           after[0][cap] = 0;
           after[1][cap] = 0;
         }
         for(int ind =n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy) cur[buy][cap] = max((-prices[ind] +after[0][cap]),after[1][cap]);
                    else cur[buy][cap] = max((prices[ind] +after[1][cap-1]),after[0][cap]);
                }
            }
            after = cur;
         }  
        return after[1][2];

        
    }
};