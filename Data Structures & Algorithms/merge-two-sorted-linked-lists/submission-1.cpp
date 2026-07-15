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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode *temp=new ListNode(0);
        ListNode *e=temp;
        while(list1 && list2){
            if(list1->val < list2->val){
                e->next=list1;
                list1=list1->next;
                e=e->next;
            }else{
                e->next=list2;
                list2=list2->next;
                e=e->next;
            }
        }
        if(list1){
            e->next=list1;
        }else if(list2){
            e->next=list2;
        }
        return temp->next;
        
    }
};
