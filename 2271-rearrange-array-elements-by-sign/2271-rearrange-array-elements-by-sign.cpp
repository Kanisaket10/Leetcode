class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;

        vector<int> newarr(n);

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                newarr[pos] = nums[i];
                pos +=2;
            }
            else{
                newarr[neg] = nums[i];
                neg +=2;
            }
        }
     return newarr;
    }
};