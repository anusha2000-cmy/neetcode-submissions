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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* rev=reverse(slow->next);
        slow->next=nullptr;
        ListNode* curr=head->next;
        ListNode* res=head;
        while(curr && rev){
            res->next=rev;
            rev=rev->next;
            res=res->next;
            res->next=curr;
            curr=curr->next;
            res=res->next;
        }
    }

    ListNode* reverse(ListNode* node){
        ListNode* prev=nullptr;
        ListNode* curr=node;
        ListNode* next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
