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
    
    TreeNode* BST(vector<int>& preorder, int upper, int lower, int& idx){
        if(idx == preorder.size() || preorder[idx]< lower || preorder[idx]>upper){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = BST(preorder, root->val, lower, idx); 
        root->right = BST(preorder, upper, root->val, idx);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, INT_MAX, INT_MIN, index);
    }
};