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
    void swap(ListNode* s,ListNode* prev){
        if(!s|| !s->next){
            return;
        }
        ListNode* nn=s;
        s=s->next;
        nn->next=s->next;
        s->next=nn;
        if(prev){
            prev->next=s;
        }
        prev=nn;
        swap(nn->next,prev);
        
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head|| !head->next){
            return head;
        }
        ListNode* temp = head;
        ListNode* a=head->next;
        ListNode* prev=nullptr;
        swap(temp,prev);
        return a;
    }
};