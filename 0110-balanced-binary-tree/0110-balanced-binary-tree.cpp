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
    int height(TreeNode* root, bool& bal){
        if(!root) return 0;   
        
        int l = height(root->left, bal);
        if(bal)
        {  int r = height(root->right, bal);
           if(abs(l-r) > 1) bal = 0;
           return 1+ max(l,r); 
        }
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        bool bal = 1;
        int h = height(root, bal);
        return bal;
         
    }
};