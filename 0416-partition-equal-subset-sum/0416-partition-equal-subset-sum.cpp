class Solution {
public:
     //  Memoization
    bool f(int ind, int target,vector<int>& nums, vector<vector<int>>& dp){
       if(target== 0) return 1;
       if(ind == 0) return nums[0] == target;

       if(dp[ind][target] !=-1) return dp[ind][target];

       bool not_take = f(ind-1, target, nums, dp);
       bool take = false;
       if(nums[ind] <= target) take = f(ind-1, target-nums[ind], nums, dp);
       return dp[ind][target]= take| not_take;
    }
    
    bool SubsetSum(vector<int>& nums, int n, int target){
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return f(n-1, target, nums, dp);
        
        // Space optimization
        // TC = O(n*target) and SC = O(target)
       vector<bool> prev(target+1, 0), curr(target+1, 0);
       prev[0]= curr[0] = true;
       if(nums[0] <= target) curr[0] = true;
       
       for(int i= 1; i<n; i++){
        for(int k=1; k<= target; k++){
            bool not_take = prev[k];
            bool take = false;
            if(nums[i] <= k) take = prev[k-nums[i]];
            curr[k] = take| not_take;
        }
        prev = curr;
       }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum =0;

       for(int i=0; i<n; i++) sum+=nums[i];
       if(sum % 2) return 0;
       int target = sum/2;
       
       return SubsetSum(nums,n, target); 
    }
};