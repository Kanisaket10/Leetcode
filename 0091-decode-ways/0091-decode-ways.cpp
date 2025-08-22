class Solution {
public:
   // Memoization
    int dp[101];
    int solve(int ind, string s){
        if(ind == 0) return 1;
        if(ind == 1) return s[0] != '0';
        
        if(dp[ind] != -1) return dp[ind];

        int one  = s[ind-1]- '0';
        int two = stoi(s.substr(ind-2, 2));
        
        int ways = 0;

        if( 1<= one && one <= 9){
            ways += solve(ind -1, s);
        } 

        if(10 <= two && two <= 26){
            ways += solve(ind -2, s);
        }

        return dp[ind] = ways;
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        int n = s.size();
        memset(dp, -1, sizeof(dp));
       
      //  return solve(n, s);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
       
        for(int i=2; i<=n; i++){

           int one  = s[i-1]- '0';
           int two = (s[i-2] - '0') * 10 + (s[i-1] - '0');

           if(one != 0) dp[i] += dp[i-1];
           if(10 <=two && two <= 26) dp[i] += dp[i-2];
        }
      return dp[n];
    }
};