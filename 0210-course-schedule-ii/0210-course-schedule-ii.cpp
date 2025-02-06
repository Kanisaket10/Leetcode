class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int>Indeg(numCourses, 0);

        for(auto& edge: prerequisites){
            int u = edge[1];
            int v = edge[0];
            graph[u].push_back(v);
            Indeg[v]++;
        }

        vector<int> ans;
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(!Indeg[i]) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto v: graph[node]){
                Indeg[v]--;
                if(!Indeg[v]) q.push(v);
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};