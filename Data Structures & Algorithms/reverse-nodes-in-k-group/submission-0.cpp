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
    ListNode* reverseKGroup(ListNode* head, int kk) {
        if(!head || !head->next){
            return head;
        }
        ListNode* dummy=new ListNode(0,head);
        ListNode* groupPrev=dummy;
        while(true){
            ListNode* k=getK(groupPrev,kk);
            if(!k)
                break;
            ListNode* groupNext=k->next;
            ListNode* prev=k->next;
            ListNode* curr=groupPrev->next;
            while(curr!=groupNext){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            ListNode* tmp=groupPrev->next;
            groupPrev->next=k;
            groupPrev=tmp;
            
        }
        return dummy->next;

    }

    ListNode* getK(ListNode* curr,int k){
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }


};
