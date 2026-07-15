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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        for(int i=1;i<=n;i++){
            curr=curr->next;
        }
        ListNode* curr1=head;
        ListNode* prev=nullptr;
        while(curr){
            curr=curr->next;
            prev=curr1;
            curr1=curr1->next;
        }
        if(curr1==head){
            return head->next;
        }else{
            prev->next=curr1->next;
            delete curr1;
        }
        return head;
    }
};
