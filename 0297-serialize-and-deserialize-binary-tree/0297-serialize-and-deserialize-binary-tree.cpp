/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";
        string s;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
           TreeNode* temp = q.front();
           q.pop();
           
           if(temp){
              s += (to_string(temp->val) + ',');
              q.push(temp->left);
              q.push(temp->right);
           }
           else{
              s += "null,";
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null") return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!getline(ss, str, ',')) break;
            if(str != "null"){
               node->left = new TreeNode(stoi(str));
               q.push(node->left);
            }

            if(!getline(ss, str, ',')) break;
            if(str != "null"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        } 
       
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));