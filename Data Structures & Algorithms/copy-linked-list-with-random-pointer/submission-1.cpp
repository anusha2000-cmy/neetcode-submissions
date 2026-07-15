/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*,Node*> m;
        Node* curr=head;
        Node* newHead;
        Node* curr1;
        while(curr){
            Node* temp=new Node(curr->val);
            m[curr]=temp;
            if(curr==head){
                newHead=temp;
                curr1=temp;
            }else{
                curr1->next=temp;
                curr1=curr1->next;
            }
            curr=curr->next;
        }
        curr=head;
        curr1=newHead;
        while(curr){
            curr1->random=m[curr->random];
            curr=curr->next;
            curr1=curr1->next;
        }
        return newHead;

        
    }
};
