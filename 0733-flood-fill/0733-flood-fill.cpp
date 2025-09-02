class Solution {
public:
     int dirrow[4] = {-1, 0, 1, 0};
     int dircol[4] = {0, 1, 0, -1};

    bool valid(int i, int j, int n, int m){
         return i>=0 && i<n && j>=0 && j<m;
    }
    
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int inicolor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++){
            int r = row + dirrow[i];
            int c = col + dircol[i];

            if(valid(r, c, n, m) && image[r][c] == inicolor && ans[r][c] != color){
                dfs(r, c, ans, image, color, inicolor);
            }
        }

    }

    void bfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int inicolor){
        
        int n = image.size();
        int m = image[0].size();

        ans[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            ans[r][c] = color;
            q.pop();

            for(int j=0; j<4; j++){
                int dr = r + dirrow[j];
                int dc = c + dircol[j];

                if(valid(dr, dc, n, m) && image[dr][dc] == inicolor && ans[dr][dc] != color){
                    q.push({dr, dc});
                }
            }

        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;

       // dfs(sr, sc, ans, image, color, inicolor);
        bfs(sr, sc, ans, image, color, inicolor);
        return ans;
    }
};