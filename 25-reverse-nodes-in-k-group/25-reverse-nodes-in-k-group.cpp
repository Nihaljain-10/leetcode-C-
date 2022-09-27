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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
            return head;
        ListNode*d=new ListNode(0);
        d->next=head;
        ListNode*cur=d,*prev=d,*nextnode=d;
        int count=0;
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }
        while(count>=k){
            cur=prev->next;
            nextnode=cur->next;
            for(int i=1;i<k;i++){
               cur->next=nextnode->next;
                nextnode->next=prev->next;
                prev->next=nextnode;
                nextnode=cur->next;
            }
            prev=cur;
            count-=k;
        }
       return d->next; 
    }
};