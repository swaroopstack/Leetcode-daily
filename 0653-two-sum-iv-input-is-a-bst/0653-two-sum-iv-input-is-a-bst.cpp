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
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root) return;

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]==k){
                return true;
            }
            else{
                if(nums[start]+nums[end]>k){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return false;
    }
};