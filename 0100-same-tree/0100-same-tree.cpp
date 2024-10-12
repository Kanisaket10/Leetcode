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
    
    void check(TreeNode* p, TreeNode*q, bool& valid){
        if(!p && !q) return;
        if(p->val != q->val){ 
           valid =0;
           return;
        }

        //if p'left exist but q's not or p'right exist but q's not
        if((p->left && !q->left) || (!p->left && q->left) ||(p->right && !q->right) ||(!p->right && q->right)){
            valid =0;
            return;
        } 
           
          // if left exist but not equal
        if((p->left && q->left) && p->left->val != q->left->val){
            valid =0;
            return;
        }
        // if right exist but not equal
        if((p->right && q->right) && p->right->val != q->right->val){
            valid =0;
            return;
        }

        if(p->left && q->left)  check(p->left, q->left, valid);
        if(p->right && q->right) check(q->right, q->right, valid);
        
    }
   
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p  || !q) return 0;
        if(p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
        }
        return 0;
    }
};