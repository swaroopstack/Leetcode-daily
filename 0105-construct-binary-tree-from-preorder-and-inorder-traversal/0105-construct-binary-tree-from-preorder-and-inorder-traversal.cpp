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
    unordered_map<int,int> mp;
    int index;
    TreeNode* solve(int start,int end,vector<int>& preorder){
        if(start>end){
            return nullptr;
        }
        int root_val=preorder[index++];
        int root_idx=mp[root_val];
        TreeNode* root=new TreeNode(root_val);
        root->left=solve(start,root_idx-1,preorder);
        root->right=solve(root_idx+1,end,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        index=0;
        return solve(0,n-1,preorder);
    }
};