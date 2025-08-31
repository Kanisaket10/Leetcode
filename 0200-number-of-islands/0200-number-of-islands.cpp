class Solution {
public:
    
    bool valid(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt =0;
        queue<pair<int, int>> q;
         
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    q.push({i, j});
                    cnt++;

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int d =0; d<4; d++){
                            int nr = r + dir[d][0];
                            int nc = c + dir[d][1];
                            if(valid(nr, nc, n, m ) && grid[nr][nc] == '1'){
                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

    return cnt;
    }
};