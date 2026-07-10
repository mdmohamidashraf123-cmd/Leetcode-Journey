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
        int c=0;
        if(!head){
            return head;
        }
        if(!head->next){
            head=nullptr;
            return head;
        }
        bool a=false;
        while(temp){
            if(!a){
             count++;
            }else{  
             if(n==count){
                     head=head->next;
                     break;
              }
             if(c==count-n-1){
                 if(temp && temp->next){
                  ListNode* t=temp->next->next;
                // delete temp->next;
                  temp->next=t;
                 }
                 break;
            }
            c++;
            }
            temp=temp->next;
            if(!temp){
                a=true;
                temp=head;
            }

        }
        return head;
    }
};