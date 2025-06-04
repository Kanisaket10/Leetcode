class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n= nums.size();
        int l=0, r=0;

        for(int i=0; i<n; i++){
            if(nums[i] != val){
                nums[l] = nums[i];
                l++;
            } 
            
        }
         return l;
    }
   
};