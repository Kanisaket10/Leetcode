class Solution {
public:
    int majorityElement(vector<int>& nums) {

      int majele;  
      int cnt=0;
      for(int i=0;i<nums.size();i++){
        if(cnt == 0){
            majele = nums[i];
            cnt++;
        }
        else if(nums[i] == majele){
            cnt++;
        }
        else{
            cnt--;
        }
      }
     return majele;

    }
};