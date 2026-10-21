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
    string ans;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        string num=to_string(root->val);
        ans+=num;
        if(root->left){
            ans+="(";
            dfs(root->left);
        }
        else{
            if(root->right){
                ans+="()";
            }
            else{
                ans+=")";
                return;
            }
        }
        if(root->right){
            ans+="(";
            dfs(root->right);
            ans+=")";
        }
        else{
            ans+=")";
            return;
        }
        
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        ans.pop_back();
        return ans;
    }
};