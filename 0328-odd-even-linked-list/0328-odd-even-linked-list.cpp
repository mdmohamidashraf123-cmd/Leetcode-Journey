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
    ListNode* oddEvenList(ListNode* head) {
      ListNode* temp=head;
      int c=0;
      if(!head || !head->next || !head->next->next){
        return head;
      }
      ListNode* a=head;
      ListNode* b=head->next;
      ListNode* d=head->next;
      temp=b->next;
      while(temp){
        c++;
        if(c%2!=0){
            a->next=temp;
            a=a->next;
        }else{
            b->next=temp;
            b=b->next;
        }
        temp=temp->next;
      }
      b->next=nullptr;
      a->next=d;
      return head;
    }
};