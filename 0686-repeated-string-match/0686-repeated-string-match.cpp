class Solution {
public:
    void findlps(vector<int>& lps, string s){
        int pre =0, suf =1;

        while(suf < s.size()){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre ==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
    }

    bool Match_KMP(string a, string b){
        int m = a.size(), n= b.size();
        vector<int> lps(n,0);
        findlps(lps, b);

        int first =0, second=0;

        while(first < m &&  second < n){
            if(a[first] == b[second]){
                first++;
                second++;
            }
            else{
                if(second == 0){
                    first++;
                }
                else{
                  second = lps[second-1];
                }
            }
        }
        if(second == n) return 1;
        return 0;
    }


    
    int repeatedStringMatch(string a, string b) {
        
        if(a == b) return 1;
        string temp = a;
        int rep = 1;

        while(temp.size() < b.size()){
            temp +=a;
            rep++;
        }
          //cout<<rep<<" ";
        //Match_KMP
          if(Match_KMP(temp, b)) return rep;

        // if Not Match add string a one more time in temp and check again 
         // cout<<rep<<" "; 
          if(Match_KMP(temp+a, b) ) return rep+1;
          return -1;

    }
};