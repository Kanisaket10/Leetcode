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
    void flatten(TreeNode* root) {
        if(!root) return;
        // Morris Traverseal
        TreeNode* temp = root;
        while(temp){
            //If left doesn't exist 
           if(!temp->left){
            temp = temp->right;
           }  
           // if left exist
           else{
               TreeNode* curr = temp->left;
               while(curr->right){
                   curr = curr->right;
               } 
              
                curr->right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
                temp = temp->right;
                
            }
        }
    }
};