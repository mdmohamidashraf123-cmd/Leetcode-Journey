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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        if(!head || !head->next){
            return ;
        }
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse slow to last node
        while(slow){
         ListNode* nn =slow->next;
         slow->next=prev;
         prev=slow;
         if(!nn){
            break;
         }
         slow=nn;
        }
        temp->next=nullptr;
        //now merge
        temp=head;

        // b=slow;
        while( temp && prev){
            ListNode* nn =temp->next;
            ListNode* z=prev->next;
            temp->next=prev;
            if(nn){
              prev->next=nn;
            }
            prev=z;
            temp=nn;
        }
        
    }
};