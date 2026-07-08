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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> vals;
        ListNode* temp= head;
        while(temp!=nullptr){
            vals.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* dummy =new ListNode(0);
        dummy->next=head;
        for(int i=0;i<vals.size();i=i+2){
            head->val=vals[i];
            head=head->next;
        }
        for(int i=1;i<vals.size();i=i+2){
            head->val=vals[i];
            head=head->next;
        }
        return dummy->next;
    }
};