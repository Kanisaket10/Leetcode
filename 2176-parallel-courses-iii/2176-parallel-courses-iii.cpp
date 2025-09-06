class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> adj[n];
        vector<int> Indeg(n, 0);

        for(int i=0; i<relations.size(); i++){
            // converting 1-based into 0-based index
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            Indeg[relations[i][1]-1]++;
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<adj[i].size();j++){
        //         Indeg[adj[i][j]]++;
        //     }
        // }
        
        queue<int> q;

        for(int i=0; i<n; i++){
           if(!Indeg[i])
             q.push(i);
        }
        vector<int> courseTime(n,0);

        while(!q.empty()){
          int node = q.front();
          q.pop();

          for(int j=0; j<adj[node].size(); j++)
          {
            Indeg[adj[node][j]]--;
            if(!Indeg[adj[node][j]])
              q.push(adj[node][j]);

            courseTime[adj[node][j]] =max(courseTime[adj[node][j]], courseTime[node]+time[node]); 
            
          } 
        }
        int ans =0;
        for(int i=0; i<n; i++){
            ans = max(ans, courseTime[i]+time[i]);
        }
       return ans;
    }
};