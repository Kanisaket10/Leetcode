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

    bool flag = 1;
    void check(TreeNode* p, TreeNode* q){
        if(!flag) return;
        if(!p && !q) return;
        if(!p || !q){
            flag = 0;
            return;
        }

        if(p->val == q->val){
            check(p->left, q->right);
            check(p->right, q->left);
        }
        else{
            flag = 0;
            return;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
       if(!root) return 1;
       check(root->left, root->right);
       return flag;
    }
};