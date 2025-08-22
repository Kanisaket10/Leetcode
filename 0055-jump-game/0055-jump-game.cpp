class Solution {
public:
    int dp[100001];
    bool helper(int ind ,int n, vector<int> nums){
        if(ind == n-1 ) return 1;

        if(dp[ind] != -1) return dp[ind];
        
        int maxjump = nums[ind];

        for(int j = 1; j <= maxjump;  j++){
            if(ind + j < n && helper(ind+j, n, nums)) 
               return dp[ind] = true;
        }
       
        return dp[ind] = false;     
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        //return helper(0, n, nums);

        // Greedy 
        int reach =0;
        for(int i=0; i<n; i++){
            if(i > reach) return false;
            reach = max(reach, i + nums[i]);
        }
       return true;
    }
};