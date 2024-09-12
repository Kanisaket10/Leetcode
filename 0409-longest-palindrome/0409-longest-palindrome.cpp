class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<int,int> mp;
        for(auto ch: s){
            mp[ch]++;
        }
        int cnt =0;

        for(auto x:mp){
            if(x.second>1) cnt +=x.second-(x.second%2);
        }
        if(cnt<n) cnt+=1;
        return cnt;



        // vector<int> loweralp(26,0), upperalp(26,0);

        // for(int i=0; i<n; i++){
        //     if(s[i] >= 'a')  loweralp[s[i]-'a']++;
        //     else  upperalp[s[i] -'A']++;
        // }
        // int cnt =0;
        // int odd =0;
        // for(int i=0; i<26; i++){
        //     if(loweralp[i]%2==0) cnt +=loweralp[i];
        //     else{
        //         odd =1;
        //         cnt +=loweralp[i]-1;
        //     }
        // }
        // for(int i=0; i<26; i++){
        //     if(upperalp[i]%2==0) cnt +=upperalp[i];
        //     else{
        //         odd =1;
        //         cnt +=upperalp[i]-1;
        //     }
        // }

        // return (odd==1)? cnt+1:cnt;

    }
};