class Solution {
public:
    long long minimumSteps(string s) {
        int  n = s.size();
        long long white = 0;
        long long cnt =0;

        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                cnt+= white;
            }      // add the no. of 1's seen so far to the result
            else if(s[i] == '1'){
                white++;     // increment ccnt of  1's
            }
        }
       
        return cnt;
    }
};