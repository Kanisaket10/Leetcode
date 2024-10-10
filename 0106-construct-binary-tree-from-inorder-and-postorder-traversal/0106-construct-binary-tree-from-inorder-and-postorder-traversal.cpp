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
    int find(vector<int>& inorder, int start, int end, int target){
        for(int i=start; i <= end; i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int start, int end, int idx){
          if(start > end){
            return NULL;
          }
          TreeNode* root = new TreeNode(postorder[idx]);
          int pos = find(inorder, start, end, postorder[idx]);

          root->right = tree(inorder, postorder, pos+1, end, idx-1);
          root->left = tree(inorder, postorder, start, pos-1, idx-(end-pos)-1);

          return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        //if we apply same code of in\pre then the ans will NLR  so if we do NRL
        // and then reverse it we will get LRN which is our required answer
        // but here we have to take index from the last of postorder
        int n = inorder.size();
        int start =0, end = n-1;
        int idx = n-1;    // in postorder position of root node would be in last  
        return tree(inorder, postorder, start, end, idx);  
    }
};