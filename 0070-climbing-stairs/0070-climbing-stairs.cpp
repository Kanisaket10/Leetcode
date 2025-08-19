class Solution {
public:
// By recursion
    int dp[46];
    int climbS(int n) {
        //memoization Approach
        if(n <= 2) return n;
        if(dp[n] !=-1) return dp[n];

        return dp[n] = climbS(n-1) + climbS(n-2);
        
    }

    int climbStairs(int n) {
        if(n <= 2) return n;
        memset(dp, -1, sizeof(dp));
        climbS(n);
        return dp[n];
        // Tabulation Approach
      
       int prev2 =1;
       int prev = 2;
       int ans =0;

        for(int i =3; i<=n; i++){
            
            ans = prev2 + prev;
            prev2 = prev;
            prev = ans;
        }
     //return ans;
    }
};