class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p=0, q=0,  ans=0;

        while(p<m && q<n){
            if(g[p] <=s[q]){
                p++;
                ans++;
            }
            q++;
        }
        return ans;
        
    }
};