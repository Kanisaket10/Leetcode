class Solution {
public:
    int countways(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){
            if(target ==0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0])  return 1;
            return 0;
        }
            if(dp[ind][target] != -1) return dp[ind][target];
            int notTake = countways(ind-1, target, nums, dp);
            int take =0;
            if(nums[ind] <= target) take = countways(ind-1, target- nums[ind], nums, dp);
            return dp[ind][target] = take+ notTake;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int totsum =0;
        
        for(int i=0; i<n; i++) totsum+=nums[i];
        if(totsum-target <0 || (totsum-target)% 2) return 0;
        int D = (totsum- target)/2;
        // vector<vector<int>> dp(n, vector<int>(D+1, -1));
        //  return countways(n-1, D, nums, dp);
     
     // Tabulation with Space  Optimization
        // vector<vector<int>> dp(n, vector<int>(D+1, 0)); 
        vector<int>prev(D+1, 0), curr(D+1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] =1;
        if(nums[0] !=0 && nums[0] <= D) prev[nums[0]] =1;

        for(int i =1; i<n; i++){
            for(int t= 0; t<=D; t++){
                 int notTake = prev[t];
            int take =0;
            if(nums[i] <= t) take = prev[t-nums[i]];
            curr[t] = take+ notTake;
            }
            prev = curr;
        }
       return prev[D];
    }
};