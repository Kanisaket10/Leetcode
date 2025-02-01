class Solution {
public:

    // dfs by Recurrsion
    void dfs(int node, vector<int> adj[], vector<bool>& visited){
         
        visited[node]=1;

        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i], adj, visited);
            }
        }
    }
    
    // dfs By Stack 

     void dfs_stack(int node, vector<int> adj[], vector<bool>& visited){
        visited[node] = 1;

        stack<int> st;
        st.push(node);

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            
            // if(!visited[ele]){
            //     visited[ele] =1;
            // }

            for(int i=0; i<adj[ele].size(); i++){
                if(!visited[adj[ele][i]]){
                    visited[adj[ele][i]] = 1;
                    st.push(adj[ele][i]);
                }
            }
        }
     }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];

     // Making adj list 
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(v, 0);
        int cnt =0;

        for(int i=0; i<v; i++){
            if(!visited[i]){  

               // dfs(i, adj, visited);
                dfs_stack(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};