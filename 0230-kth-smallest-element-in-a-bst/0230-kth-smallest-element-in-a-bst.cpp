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
    
    void find_k(TreeNode* root, int& k, int& ans){
        if(!root) return;

// INORDER Traversal because it gives us ascending order of BST
        find_k(root->left, k, ans);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        else if(k < 0) return;       
        find_k(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        //int prev = INT_MIN;
        int ans;
        find_k(root, k, ans);
        return ans;
    }
};