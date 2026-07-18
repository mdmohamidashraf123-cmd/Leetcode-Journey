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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            if(temp->val==val){
                if(!prev){
                    head=head->next;
                    ListNode* nn=temp;
                    nn->next=nullptr;
                    delete nn;
                    temp=head;
                }else{
                    ListNode* nn=temp;
                    prev->next=temp->next;
                    temp=prev->next;
                    nn->next=nullptr;
                    delete nn;
                     
                }
            }else{
             prev=temp;
             temp=temp->next;
            }
        }
        return head;
    }
};