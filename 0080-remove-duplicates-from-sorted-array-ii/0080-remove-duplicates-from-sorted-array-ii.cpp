class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            if(ans ==0 || ans == 1 || nums[ans-2] != nums[i]){
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
};