              // Using Inbuilt function
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         // using InBuilt function sunstr
//         int n = needle.size();
//         int m = haystack.size();
//         for(int i = 0; i<= m-n;++i){
//           if(haystack.substr(i,n) == needle){
//             return i;
//           }
//         }
//         return -1;
//     }
// };
              // brute force approch
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
         
//          int m = haystack.size();
//          int n = needle.size();
         
//          for(int i=0; i<=m-n; i++){
//               int first =i, second =0;

//               while(second < n){
//                   if(haystack[first] != needle[second]) {break;}
//                   else{
//                     first++;
//                     second++;
//                   }
//               }
//               if(second == n) return first-second;
//          }
//          return -1;
//     }
// };    
             // Optimized Using KMP
               

class Solution {
public:
    void findlps(vector<int>& lps, string s){
       int pre =0, suf =1;
       
       while(suf < s.size()){
          if(s[pre] == s[suf]){
            lps[suf] = pre+1;
            suf++; pre++;
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
    int strStr(string haystack, string needle) {
        // using LPS (Longest Prefix Suffix)
        
        int m = haystack.size();
        int n = needle.size();
        vector<int> lps(n);
        findlps(lps, needle);
        int first =0, second=0;
        while(first < m && second < n){
            if(haystack[first] == needle[second]){
               first++; second++;
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
        if(second == n ) return first - second;
      
        return -1;
    }
};