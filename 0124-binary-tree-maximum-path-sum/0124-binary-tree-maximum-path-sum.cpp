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
    int maxsum = INT_MIN;
    int findsum(TreeNode* root){
        if(!root) return 0;
        
        //leaf node
        // if(!root->left && !root->right){
        //     return root->val;
        // }

        int l = max(findsum(root->left),0 );
        int r = max(findsum(root->right),0);

         maxsum = max(maxsum, l + r + root->val);
         return root->val + max(l, r);
       
      
    }

    int maxPathSum(TreeNode* root) {
        
        findsum(root);
        return maxsum; 
       
    }
};