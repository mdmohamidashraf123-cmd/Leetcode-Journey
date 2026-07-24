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
        ListNode* temp=head;
        ListNode* fast=head;
        int count=0;
        if(!head){
            return head;
        }
        if(!head->next){
            head=nullptr;
            return head;
        }
        for (int i = 0; i < n; i++) {
           fast = fast->next;
        }
        if(!fast){
            head=head->next;
            return head;
        }
        temp=head;
        while(fast && fast->next){
            fast=fast->next;
            temp=temp->next;
        } 
        ListNode* t=temp->next;
        temp->next=t->next;
        delete t;
        return head;
    }
};