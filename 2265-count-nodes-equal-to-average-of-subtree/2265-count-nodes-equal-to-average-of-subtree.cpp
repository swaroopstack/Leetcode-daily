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
    int ans=0;
    pair<int,int> average(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> left= average(root->left);
        pair<int,int> right=average(root->right);
        int sum=left.first+right.first+root->val;
        int count=left.second+right.second+1;
        int avg=sum/count;
        if(root->val==avg){
            ans++;
        }
        return {sum,count};
        
    }
    int averageOfSubtree(TreeNode* root) {
        average(root);
        return ans;
    }
};