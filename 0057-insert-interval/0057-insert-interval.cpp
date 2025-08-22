class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int first=intervals[0][0];
        int second=intervals[0][1];

       for(int i=0;i<intervals.size()-1;i++){
          if(second>=intervals[i+1][0])
          second=max(second,intervals[i+1][1]);         // overlapping.

          else{
            vector<int>temp;
            temp.push_back(first);
            temp.push_back(second);
            ans.push_back(temp);
            first=intervals[i+1][0];
            second=intervals[i+1][1];
          }
       }

       ans.push_back({first,second});

       return ans;
    }
};