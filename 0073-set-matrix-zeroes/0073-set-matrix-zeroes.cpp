class Solution {
public:
    void makingRowColZero(vector<vector<int>>& matrix, int row, int col, int m, int n){
         // Making Row Zero 
         for(int i=0; i<m; i++){
            matrix[i][col] = 0;
         }

         // Making Column Zero
         for(int j=0; j<n; j++){
            matrix[row][j] =0;
         }
    }
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       //int row, col;
       int cnt = 0;
       vector<pair<int, int>> store;
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                // makingRowColZero(matrix, i, j, m ,n);
                 cnt++;
                 store.push_back({i, j});
            }
        }
       }
       for(int i=0; i<cnt; i++){
          int row = store[i].first;
          int col = store[i].second;
          makingRowColZero(matrix, row, col, m, n);
       }

    }
};