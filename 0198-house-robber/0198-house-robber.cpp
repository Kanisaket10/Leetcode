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
        // memoization
          // vector<int> dp(n, -1);
          // return maxrobbery(n-1, nums, dp);

        // Tabulation 
        //  if(n<2) return nums[0]; 
        //  vector<int> dp(n, -1);
        //  dp[0] = nums[0];
        //  dp[1] = max(nums[0], nums[1]);

        //  for(int i=2; i<n; i++){
        //     dp[i] = max((nums[i]+ dp[i-2]), dp[i-1]);
        //  }
        //  return dp[n-1];

         //space optimization
         if(n<2) return nums[0]; 
         int prev2 = nums[0];
         int prev = max(nums[0], nums[1]);
         int curr;
         for(int i=2; i<n; i++){
             curr = max((nums[i]+prev2), prev);
             prev2 = prev;
             prev = curr;
         }
         return prev;
    }
};