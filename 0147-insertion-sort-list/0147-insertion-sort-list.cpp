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
    ListNode* insertionSortList(ListNode* head) {
        if(!head ||!head->next){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* p=head;
        while(temp){
            ListNode* n=temp->next;
            ListNode* prev=nullptr;
            ListNode* cn=head;
            while(cn && cn!=temp){
              if(cn->val>temp->val){
               if(prev){
                if(cn->next==temp){
                    cn->next=temp->next;
                }else{
                    p->next=temp->next;
                }
                prev->next=temp;
                temp->next=cn;
               }else{
                head=temp;
                if(cn->next==temp){
                 cn->next=temp->next;
                }else{ 
                  p->next=temp->next;
                }
                temp->next=cn;
               }
               break;
              }
              prev=cn;
              cn=cn->next;
            }
            if(cn==temp){
             p=temp;
            }
            temp=n;
        }
        return head;
    }
};