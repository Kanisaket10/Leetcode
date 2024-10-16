/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
          
        bool flag = 1;   // 1 for left to right  
                           // 0 for right to left
        while(!q.empty()){
            int n = q.size();
            vector<int> vec(n);
                 
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(flag){
                  vec[i] = temp->val;
                } 
                else{
                    vec[n-i-1] = temp->val;
                } 

                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(vec);
           
           //flip the direction for the next level
            flag = !flag;
        }
        return ans;
    }
};