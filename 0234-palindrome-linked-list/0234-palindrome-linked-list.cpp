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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* c;
        while(fast && fast->next){
            c=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        c->next=nullptr;
        //reverse half of the list
        while(slow){
            ListNode* a=slow->next;
            slow->next=prev;
            prev=slow;
            slow=a;
        }
        while(temp && prev){
            if(temp->val!=prev->val){
                return false;
            }
            temp=temp->next;
            prev=prev->next;
        }
        return true;
        
    }
};