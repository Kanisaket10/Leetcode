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
class Solution {
public:
    int strStr(string haystack, string needle) {
         
         int m = haystack.size();
         int n = needle.size();
         
         for(int i=0; i<=m-n; i++){
              int first =i, second =0;

              while(second < n){
                  if(haystack[first] != needle[second]) {break;}
                  else{
                    first++;
                    second++;
                  }
              }
              if(second == n) return first-second;
         }
         return -1;
    }
};    

