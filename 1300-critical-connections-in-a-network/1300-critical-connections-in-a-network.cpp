class Solution {
public:
    int N;

    vector<int> disc;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> res;

    void DFS(int node, int parent, vector<vector<int>>& adj, int& cnt){
          disc[node] = low[node] = cnt;
          visited[node] = 1;

          for(int neib: adj[node]){
            if(neib == parent) continue;
            else if(visited[neib]){
                 low[node] = min(low[node], low[neib]);
            }
            else{
                cnt++;
                DFS(neib, node, adj, cnt);

                if(disc[node] < low[neib]){
                    res.push_back({node, neib});
                }

                low[node] = min(low[node], low[neib]);
            }
          }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        disc.assign(n, 0);
        low.assign(n, 0);
        visited.assign(n, 0);

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt =0;

        DFS(0, -1, adj, cnt);

        return res;


    }
};