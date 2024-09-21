// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
        
//         for(int i=0; )
        
//     }

// };
class Solution {  
public:  
   int firstMissingPositive(vector<int>& nums) {  
      if (nums.empty()) {  
        return 1;  
      }  
  
      int n = nums.size();  
      for (int i = 0; i < n; i++) {  
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {  
           swap(nums[nums[i] - 1], nums[i]);  
        }  
      }  
  
      for (int i = 0; i < n; i++) {  
        if (nums[i] != i + 1) {  
           return i + 1;  
        }  
      }  
  
      return n + 1;  
   }  
};






// int j, i, k;
        // int max= INT_MIN;
        

        // for(int i=0; i<nums.size(); i++){
        //     if(max < nums[i] ) max = nums[i];
        // }
        // vector<int> freq(max,0);

        // for(int j=0;j<=max;j++){
        //     if(nums[j] >= 0) {freq[nums[j]]++;}
        // }

        // for(int k=0;k<=max;k++ ){
        //     if((k >=1 ) && (freq[k] == 0) ){
              
        //         return k;
              
        //     }
            
        // }

        // return max+1;
