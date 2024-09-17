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
//   int cnt =0, zr=0;
//   for(int i=0; i<n; i++){
//     if(nums[i]) cnt++;
//     if(!nums[i]) zr++;
//     if(cnt == n) return n;
//     if(zr == n)  return 0;
//   }
//   if(n <= 1 &&  !nums[0]) return 0;
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

    //     int front =0;
    //     int last = 1;
    //     int maxCon = 0;
    //    for(int i=0; i<nums.size()-1; i++)
    //     {
    //         if(!nums[front] && !nums[last]){
    //           maxCon = max(maxCon,last-front+1);
    //           front++; 
    //           last--;
    //         }
    //         else if(!nums[front] && nums[last]) front++;
    //         else if(nums[front] && !nums[last]) last--;

    //     }
    //   return maxCon;
    }
};