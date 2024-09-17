class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

     // Brute force
//      int mx =0;
//      for(int i=0; i<n; i++){
//         int cnt =0;
//         for(int j=i; j<n; j++){
//             if(nums[j]==1){
//                 cnt++;
//                 mx = max(mx, cnt);
//             }
//             else   break;
//         }
        
//      }
//   return mx;


  // optimized, making it in O(n) time complexity
   int second =0;
   int mx=0,temp =0;;
  
   while(second< n){
    
    if(nums[second]){
        temp++;
        mx = max(mx, temp);
        second++;
    }
    else {
        temp =0;
        second++;
    }
   }
  return mx;
    }
};