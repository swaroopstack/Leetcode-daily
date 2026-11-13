/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            sum+=nums[i];
            sum+=nums[n-1-i];
            ans=max(ans,sum);
        }
        return ans;
    }
};