class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int len =1;
       int mx = *max_element(nums.begin(), nums.end());

       int temp_len =0;
       for(int i=0; i<nums.size(); i++){
        
           if(nums[i] == mx){
            temp_len++;
           }
           else{
             len = max(len, temp_len);
             temp_len =0;
           }
       }
        len = max(len, temp_len);
      return len;  
    }
};