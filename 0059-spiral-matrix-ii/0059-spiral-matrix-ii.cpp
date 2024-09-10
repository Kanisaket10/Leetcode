class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int value=1;
        int top=0, left=0, right = n-1, bottom =n-1;

        // traversing the matrix
        while(top<=bottom && left<=right){
            // filling the top row
            for(int j=left; j<=right; j++){
              ans[top][j]=value;
              value++;
            }
            top++;

            //filling the right col
            for(int i=top; i<=bottom; i++){
                ans[i][right]=value;
                value++;
            }
            right--;
            // filling the bottom row
            if(top<=bottom){
                for(int j=right; j>=left; j--){
                    ans[bottom][j] = value;
                    value++;
                }
                bottom--;
            }
            // filling the left col
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    ans[i][left] = value;
                    value++;
                }
                left++;
            }
        }

        return ans;
    }
};