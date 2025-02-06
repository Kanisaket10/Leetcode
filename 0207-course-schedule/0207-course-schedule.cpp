class Solution {
public:
    bool kahnsAlgo(queue<int>& q, unordered_map<int, vector<int>>& graph, vector<int>& Indeg){
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto v: graph[node]){
                Indeg[v]--;
                if(!Indeg[v]) q.push(v);
            }
        }
        return cnt == Indeg.size();
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> Indeg(numCourses, 0);

        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            Indeg[v]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!Indeg[i]) q.push(i);
        }
        
        if(q.empty()) return 0;
        if(kahnsAlgo(q, graph, Indeg)) return 1;
        return 0;
    }
};