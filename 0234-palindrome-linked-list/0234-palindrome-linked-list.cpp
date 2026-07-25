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
        while(temp){
            ListNode*f=new ListNode(temp->val);
            f->next=prev;
            prev=f;
            temp=temp->next;
        }
        temp=head;
        while(prev&& temp){
            if(prev->val!=temp->val){
                return false;
            }
            prev=prev->next;
            temp=temp->next;
        }
        return true;
        
    }
};