class Solution {
public:
    int dir[4] = {-1, 0, 0 ,1};
    int dic[4] = {0, -1, 1, 0};

    bool valid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void BFS(int i, int j, vector<vector<char>>& board, int m, int n){
        queue<pair<int,int>> q;
        q.push({i, j});
        board[i][j] = 'T';

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
           
            q.pop();

            for(int i=0; i<4; i++){
                int dr = r + dir[i];
                int dc = c + dic[i];

                if(valid(dr, dc, m, n) && board[dr][dc] == 'O'){
                    board[dr][dc] = 'T';
                    q.push({dr, dc});
                }
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

// first && last row
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O'){
                BFS(0, j, board, m, n);
            }
            if(board[m-1][j] == 'O'){
                BFS(m-1, j, board, m, n);
            }
        }
// first && last column
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                BFS(i, 0, board, m, n);
            }
            if(board[i][n-1] == 'O'){
                BFS(i, n-1, board, m, n);
            }
             
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }       

    }
};