class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = 1;

        for(auto nei: adj[node]){
            if(!visited[nei]){
                dfs(nei, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);
        
        dfs(0, rooms, visited);

        for(int i=0; i<n; i++){
            if(visited[i] == 0) return 0;
        }
       return 1;
    }
};