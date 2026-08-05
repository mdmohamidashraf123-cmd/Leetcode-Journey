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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head->next && head->val!=0){
            return head;
        }else if(!head->next && head->val==0){
            return nullptr;
        }
        int sum=0;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
          bool f=false;
          sum+=temp->val;
          if(sum==0){
            f=true;
            if(!prev){
                head=temp->next;
            }else{
                prev->next=temp->next;
            }
            temp=temp->next;
          }else{
           ListNode* n=temp->next;
           while(n){
            sum+=n->val;
            n=n->next;
            if(sum==0){
                f=true;
                if(prev){
                    prev->next=n;
                }else{
                    head=n;
                }
                temp=n;
            }
           }
          }
          sum=0;
          if(!f){
          prev=temp;
          temp=temp->next;
          }
        }
        return head;
    }
};