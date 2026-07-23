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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        if(!head || !head->next){
            return head;
        }
        ListNode* dummynode=new ListNode(-1);
        ListNode* curr=dummynode;
        ListNode* dn=new ListNode(-1);
        ListNode* a=dn;
        while(temp){
            if(temp->val<x){
                curr->next=temp;
                curr=curr->next;
            }else{
                a->next=temp;
                a=a->next;
            }
            temp=temp->next;
        }
        a->next=nullptr;
        curr->next=dn->next;
        return dummynode->next;
    }
};