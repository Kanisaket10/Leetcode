class Solution {
public:       
           //   top left bottom right
    int dii[4] = {-1, 0, 1, 0};   //row
    int dij[4] = {0, -1, 0, 1};   // col

    int orangesRotting(vector<vector<int>>& grid) {
      
        int m = grid.size();
        int n = grid[0].size();

       queue<pair<int, int>> q;
       int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               if(grid[i][j] == 2){
                 q.push({i, j});
               }
               else if(grid[i][j] ==1){
                fresh++;
               }
            }
        } 

        int time = -1;

        if(fresh == 0) return 0;

        while(!q.empty()){
            int q_size = q.size();

            for(int i=0; i<q_size; i++){
                auto [x,y] = q.front();
                q.pop();

                for(int d =0; d<4; d++){
                    int nx = x + dii[d];
                    int ny = y + dij[d];

                    if(nx >=0 && nx < m && ny>=0 && ny<n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            
            time++;
        }

        for(int i=0; i <m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};