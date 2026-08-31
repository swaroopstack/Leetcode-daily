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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        ListNode* prev=head;
        int mindis=INT_MAX;
        int maxdis=INT_MIN;
        ListNode* temp=head->next;
        int seen=-1;
        int first=-1;
        int last=-1;
        int idx=2;
        int critical=0;
        while(temp->next){
            if(temp->val<prev->val && temp->val<temp->next->val){   // local minima
                if(first==-1){
                    first=idx;
                    seen=idx;
                }
                else{
                    mindis=min(mindis,abs(seen-idx));
                    seen=idx;
                    last=idx;
                }
                critical++;
            }
            if(temp->val>prev->val && temp->val>temp->next->val){    //local maxima
                if(first==-1){
                    first=idx;
                    seen=idx;
                }
                else{
                    mindis=min(mindis,abs(seen-idx));
                    seen=idx;
                    last=idx;
                }
                critical++;
            }
            prev=prev->next;
            temp=temp->next;
            idx++;
        }
        maxdis=abs(last-first);
        if(critical<2){
            return {-1,-1};
        }
        return {mindis,maxdis};
    }
};