class Solution {
public:
    int dp[2001];
    bool ispalindrome(string &s, int i, int j){
        while( i < j ){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j){
        if(i >= j || ispalindrome(s, i, j)) return 0;
        
        if(dp[i] != -1) return dp[i];
         
        int mn = INT_MAX;
        for(int k = i; k < j; k++){
           if(ispalindrome(s, i, k)){
              int temp = solve(s, k+1, j) +1;
              mn = min(mn, temp);
           }
        }
      return dp[i] = mn;
     
    }

    int minCut(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1);
    }
};