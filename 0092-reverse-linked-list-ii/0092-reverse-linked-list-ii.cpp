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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* end=nullptr;
        int c=0;
        if(!head->next){
            return head;
        }
        while(temp){
           c++;
           if(c==left-1){
            prev=temp;
           }
           if(c==right+1){
            end=temp;
           }
           temp=temp->next;
        }
        if(prev==nullptr){
            temp=head;
        }else{
         temp=prev->next;
        }
        ListNode* nn;
        ListNode* b=end;
        while(temp!=b){
            nn=temp->next;
            temp->next=end;
            end=temp;
            temp=nn;
        }
        if(prev){
          prev->next=end;
        }else{
            head=end;
        }
        return head;
    }
};