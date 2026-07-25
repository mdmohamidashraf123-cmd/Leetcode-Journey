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
    ListNode* reverse(ListNode*& prev,ListNode* temp){
        if(!temp|| !temp->next){
           prev=temp;
           return temp;
        }
        ListNode* nh=reverse(prev,temp->next);
        ListNode* f= temp->next;
        f->next=temp;
        temp->next=nullptr;
        return nh;


    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        if(!head || !head->next ){
            return head;
        }
        ListNode* prev=nullptr;
        ListNode*  a=reverse(prev,temp);
        return prev;
    }

};