class Solution {
public:

    void solve(vector<int>& candidates, int target, int idx, int n, vector<vector<int>>& ans, vector<int>& temp){
       
        if(target == 0){
            ans.push_back(temp);
            return;
        }
    
       for(int i=idx; i<n; i++){
         if (i > idx && candidates[i] == candidates[i - 1]) continue;
         if (candidates[i] > target) break;
         temp.push_back(candidates[i]);
         solve(candidates, target-candidates[i], i+1, n, ans, temp);
         temp.pop_back();
       }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, n, ans, temp);
        return ans; 
    }
};

// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector < vector < int >> ans;
//         vector < int > ds;
//         findCombination(0, target, candidates, ans, ds);
//         return ans;
//     }
//     void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
//         if (target == 0) {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = ind; i < arr.size(); i++) {
//             if (i > ind && arr[i] == arr[i - 1]) continue;
//             if (arr[i] > target) break;
//             ds.push_back(arr[i]);
//             findCombination(i + 1, target - arr[i], arr, ans, ds);
//             ds.pop_back();
//         }
//     }
// };