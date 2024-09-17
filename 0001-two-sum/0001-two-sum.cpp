class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        // Brute force

    //    int i,j;
    //     for(int i=0;i<n-1;i++){
    //         for(int j=i+1; j<n; j++){
    //         if((nums[i] + nums[j]) == target){
    //         return {i,j};
    //          }
    //         }
    //     }
    //   return {};

     //    optimal approach
       map<int, int> mp;
        for(int i=0; i<n; i++)
        {   int x = target - nums[i];
            if(mp.find(x) != mp.end()){
                return {mp[x], i};
            }
           
                mp[nums[i]] = i;
            
        }
        return {-1,-1};
    }
};