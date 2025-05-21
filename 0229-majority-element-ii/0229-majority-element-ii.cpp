class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t = n/3;

        map<int, int> ump;

        for(auto ele: nums){
            ump[ele]++;
        }
        vector<int> ans;

        for(auto ele : ump){
            int f = ele.first;
            int s = ele.second;

            if(s > t) ans.push_back(f);
        }
        return ans;
    }
};