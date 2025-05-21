class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); //9
    
        int currSum =0;
        int ans = INT_MIN;
    
        for(int i=0; i<n; i++){
       
            currSum +=nums[i];   // 1
            ans = max(ans, currSum);
            if(currSum < 0) currSum =0; //0
       
            
        
        }
    return ans;
    //     int sum=0;
    //     vector<int> res;
    //     int larg = INT_MIN;

    //     for(int i=0;i<nums.size();i++){
    //         sum += nums[i];
            
    //              if(sum >larg){
    //                 larg =sum;
    //              }
    //              if(sum <0){
    //                 sum = 0;
    //              }
    //     }
    //   return larg;
        
    }
};