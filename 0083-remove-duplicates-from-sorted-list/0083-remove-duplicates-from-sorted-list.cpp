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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL||temp->next==NULL){
            return head;
        }
        while(temp->next!=NULL){
            ListNode* temp1=temp->next;
            if(temp->val == temp1->val){
                temp->next=temp1->next;
                delete temp1;
               
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};