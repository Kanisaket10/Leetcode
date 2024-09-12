class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        vector<int> loweralp(26,0), upperalp(26,0);

        for(int i=0; i<n; i++){
            if(s[i] >= 'a')  loweralp[s[i]-'a']++;
            else  upperalp[s[i] -'A']++;
        }
        int cnt =0;
        int odd =0;
        for(int i=0; i<26; i++){
            if(loweralp[i]%2==0) cnt +=loweralp[i];
            else{
                odd =1;
                cnt +=loweralp[i]-1;
            }
        }
        for(int i=0; i<26; i++){
            if(upperalp[i]%2==0) cnt +=upperalp[i];
            else{
                odd =1;
                cnt +=upperalp[i]-1;
            }
        }

        return (odd==1)? cnt+1:cnt;
    }
};