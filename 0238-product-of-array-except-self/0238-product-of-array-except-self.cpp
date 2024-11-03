class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        
        int left = 1;
        for(int i=0; i<nums.size(); i++){
           ans[i] *= left;  // prefix product
           left *= nums[i]; 
        }

        int right =1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= right;  // suffix product
            right *= nums[i];
        }

        return ans;  
    }
};