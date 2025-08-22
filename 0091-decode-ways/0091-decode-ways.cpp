class Solution {
public:
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
       
        return solve(n, s);
      
    }
};