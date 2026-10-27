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
    int sum=0;
    int num=0;
    void dfs(TreeNode* root){
        if(root==nullptr){
            return;
        } 
        num=num*10+(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
        }
        dfs(root->left);
        dfs(root->right);
        num/=10;
    }
    int sumNumbers(TreeNode* root) {
        sum=0;
        num=0;
        dfs(root);
        return sum;
    }
};