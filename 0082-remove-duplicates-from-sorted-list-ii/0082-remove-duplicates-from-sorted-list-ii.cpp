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
        if(!head || !head->next){
            return head;
        }
        unordered_map<ListNode*,int>m;
        ListNode* temp=head;
        while(temp->next){
            if(temp->val==temp->next->val){
                m[temp]++;
                m[temp->next]++;
            }
            temp=temp->next;
        }
        temp=head;
        ListNode* prev=head;
        ListNode* nn;
        while(temp){
            if(m[temp]>=1){
              if(temp->next){
                nn=temp->next;
                if(temp==head){
                    head=temp->next;
                    delete temp;
                    prev=head;
                }else {
                 prev->next=temp->next;
                 delete temp;
                }
                temp=nn;
              }else{
                if(temp==head){
                    return nullptr;
                }
                delete temp;
                prev->next=nullptr;
                break;
              }
            }else{
             prev=temp;
             temp=temp->next;
            }
        }
        return head;
    }
};