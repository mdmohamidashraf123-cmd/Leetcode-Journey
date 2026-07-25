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
   void reverse(ListNode*& prev,ListNode* temp){
        if(!temp){
           return;
        }
        ListNode* a=temp->next;
        temp->next=prev;
        prev=temp;
        temp=a;
        reverse(prev,temp);
   }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        if(!head || !head->next ){
            return head;
        }
        ListNode* prev=nullptr;
        reverse(prev,temp);
        return prev;
    }

};