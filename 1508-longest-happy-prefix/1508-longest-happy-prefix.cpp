class Solution {
public:
    string longestPrefix(string s) {
        int n= s.size();
        string ans="";
        // By using KMP Algorithm
        vector<int> lps(n, 0);

        int pre =0, suf =1;
        while(suf < s.size()){
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

        int cnt = lps[n-1];
        int idx = n-1;   //4 5
        while(cnt--){    //1--=0 4--=3--=2--=1--0
            ans +=s[idx]; // l   // baba
            idx--;       //3     //4 3 2
        }
        reverse(ans.begin(), ans.end());  // abab
        return ans;     // l
    }
};
   // It gives Memory limit Exceeded
// { // brute force 
         // Time Complexity => O(nlogn)and Space Compexity O(n^2)
    //     string ans ="";
    //     vector<string> pref;
    //     vector<string> suf;
        
    //     string temp ="";
    //     for(int i=0; i<n-1; i++){
    //        temp +=s[i];
    //    //    cout<<temp<<" ";
    //        pref.push_back(temp);
    //     }

    //     string rev ="";
    //     for(int i=n-1; i>0; i--){  
    //        rev +=s[i]; 
    //        suf.push_back(rev);  // l le lev leve
    //     }
    //    //  cout<<endl;
    //     for(int i=0; i<pref.size(); i++){
    //         string rev = suf[i];
    //         reverse(rev.begin(),rev.end());  // l el vel evel
    //        // cout<<rev<<" ";
    //         if(pref[i]== rev){
    //             if(pref[i].size() > ans.size()){
    //                 ans = pref[i];
    //             }
    //         }
    //     }
    //     return ans;}