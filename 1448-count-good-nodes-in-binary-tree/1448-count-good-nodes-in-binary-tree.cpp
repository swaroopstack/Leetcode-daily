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
    int good=0;
    void solve(TreeNode* root,int top){
        if(root->val>=top){
            good++;
            top=root->val;
        }
        
        if(root->left){
            solve(root->left,top);
        }
        if(root->right){
            solve(root->right,top);
        }
    }
    int goodNodes(TreeNode* root) {
        int top=root->val;
        solve(root,top);
        return good;
    }
};