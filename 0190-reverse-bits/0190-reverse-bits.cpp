class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans =0;
        for(int i=0; i< 32; i++){
            int num = n & 1;
            ans = (ans <<1)|num;
            n =  n>>1;
        }
        return ans;
    }
};