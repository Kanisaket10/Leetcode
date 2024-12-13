class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx, int currSum, vector<vector<int>> &ans, vector<int> temp){
       
        if(currSum > target) return;
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            currSum += candidates[i];
            solve(candidates, target, i, currSum, ans, temp);
            temp.pop_back();
            currSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, 0, ans, temp);
        return ans;
    }
};