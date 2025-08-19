class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        int maxlen = 0;   // Finding the max length of the word in the wordDict;
        for(string &word : wordDict){
            maxlen = max(maxlen, (int)word.size());
        }

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j>= max(0, i-maxlen); j--){
                if(dp[j] && wordSet.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
       return dp[n];
    }
};