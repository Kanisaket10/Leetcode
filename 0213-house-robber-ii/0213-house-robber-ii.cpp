class Solution {
public:
    int findmax(vector<int>&nums){
        int curr;
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
       
        for(int i=2; i<nums.size(); i++){
           curr = max((nums[i]+ prev2), prev);
           prev2 = prev;
           prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n <= 3) return *max_element(nums.begin(), nums.end());
        vector<int> arr1, arr2;

        for(int i=0; i<n; i++){
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }

        return max(findmax(arr1), findmax(arr2));

    }
};