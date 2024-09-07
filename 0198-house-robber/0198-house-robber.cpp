class Solution {
public:
    int maxrobbery(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[0];
        if(i == 1) return max(nums[0], nums[1]);
        
        if(dp[i]!=-1) return dp[i];
      //return max((nums[i] + maxrobbery(i-2, nums)), (maxrobbery(i-1, nums)));
        return dp[i] = max((nums[i] + maxrobbery(i-2, nums, dp)), (maxrobbery(i-1, nums, dp)));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxrobbery(n-1, nums, dp);
    }
};