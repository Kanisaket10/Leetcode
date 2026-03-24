class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    // time complexity O(n)
        // int first=0;
        // int last = nums.size()-1;
        // vector<int> ans(2,-1);
        
        // while(first <= last)
        // {
        //     if(nums[first] == target){
        //         ans[0] = first;
        //         break;
        //     }
        //     else{
        //         first++;

        //     }

        // }
        // while(first <= last)
        // {
        //     if(nums[last] == target){
        //         ans[1] = last;
        //         break;
        //     }
        //     else{
        //         last--;

        //     }

        // }
        // return ans;


        // time complexity will be O(logn) because array is sorted
        // so we apply binary search

        int start =0;
        int end = nums.size()-1;
        
        vector<int> ans(2,-1);
        
        // finding first ocurrance
        while(start <= end)
        {
        int mid = start + (end- start)/2;
            if(nums[mid] == target){
                ans[0] = mid;
                end = mid-1;
            }
            else if(nums[mid] >target){
                end = mid-1;
            }
            else{
                
                start = mid+1;
            }
        }

        //finding last ocurrance 
         start =0;
         end = nums.size()-1;
        while(start <= end)
        {
        int mid = start + (end- start)/2;
            if(nums[mid] == target){
                ans[1] = mid;
                start = mid+1;
            }
            else if(nums[mid] >target){
                
                end = mid-1;
                
            }
            else{
                
                start = mid+1;
                
                
            }
        }
        return ans;

    }  
    
};