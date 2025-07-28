class Solution {
public:

// Recursion

// int Longest_Increasing_subsequence_of_length(int ind, int prev_ind, int n, vector<int>& num){
    
//     if(ind == n) return 0;
    
//     int len = Longest_Increasing_subsequence_of_length(ind +1, prev_ind, n, num);
//     if(prev_ind == -1 || num[ind] > num[prev_ind]){
//         len = max(len, 1+Longest_Increasing_subsequence_of_length(ind+1, ind, n, num));
//     }
    
//     return len;
// }

 // Memoization

int Longest_Increasing_subsequence_of_length(int ind, int prev_ind, int n, vector<int>& num, vector<vector<int>>& dp){
    
    if(ind == n) return 0;
    
    if(dp[ind][prev_ind+1] !=-1) return dp[ind][prev_ind+1];
    
    int len = Longest_Increasing_subsequence_of_length(ind +1, prev_ind, n, num, dp);
    if(prev_ind == -1 || num[ind] > num[prev_ind]){
        len = max(len, 1+Longest_Increasing_subsequence_of_length(ind+1, ind, n, num, dp));
    }
    
    return dp[ind][prev_ind+1] = len;
}

    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
     //  return Longest_Increasing_subsequence_of_length(0, -1, n, nums);
       vector<vector<int>> dp(n, vector<int>(n+1, -1));
       return Longest_Increasing_subsequence_of_length(0, -1, n, nums, dp);

       // Tabulation
       //vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));

    //    for(long long ind = n-1; ind >= 0; ind--){
    //        for(long long prev_ind = ind-1; prev_ind >=-1; prev_ind--){
    //           long long len = dp[ind+1][prev_ind+1];
    //           if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
    //                len =max(len, 1+ dp[ind+1][ind+1]);
    //             }
    //             dp[ind][prev_ind+1] = len;
    //        }
    //     }
       // return dp[0][0];
    }
};