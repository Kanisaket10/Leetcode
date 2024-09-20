class Solution {
public:
    void findlps(vector<int>& lps, string s){
        int n =s.size();

        int pre =0, suf =1;
        while(suf < n){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    lps[suf] =0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s+"$" + rev;

        int m = str.size(); 
        vector<int> lps(m, 0);
        findlps(lps, str);

        int ans = lps[m - 1]; // 1
        
        while(ans < n){
            rev +=s[ans];
            ans++;
        }

       return rev;
    }
};