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
    void InOrd(TreeNode* root,vector<int>& ans){
         if(!root) return;
      // LNR
         
         InOrd(root->left, ans);
         ans.push_back(root->val);
         InOrd(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // InOrd(root, ans);
        // return ans;

        while(root){
            //if left part doesn't exist
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }
            // if left part exist
            else{
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                // if left part is not traversed that means
                // curr->right will be equal to NULL
                if(curr->right == NULL){
                    curr->right = root;
                    root = root->left;
                }
                // if left part is traversed that means 
                //curr->right will be equal to root node 
                else{
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;   
                }
                
            }
        }
        return ans;
    }
};