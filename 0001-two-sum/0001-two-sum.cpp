class Solution {
public:
    
    // Better Apporach with TC : O(n) and SC:O(n)
    vector<int> sum(vector<int>& nums, int target){
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];  //7 ,2
            if(mp.find(need) != mp.end()){
                return {mp[need], i};
            }
            mp[nums[i]] = i; // [(2,0),]
        }
        return{};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        
        // vector<int> ans;
        // int i=0,j=1;
        // for(int i=0;i<n-1;i++){
        //     if((nums[i] + nums[j]) == target){
        //     ans.push(i);
        //     ans.push(j);
        //      }
        //      else{
        //         j++;
        //      }
        // }
      //return ans;
      return sum(nums, target);
    }
};