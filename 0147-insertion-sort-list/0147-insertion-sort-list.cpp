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
        ListNode* dummy=new ListNode(0);
        ListNode* temp=head;
        while(temp){
            ListNode* c=temp->next;
            ListNode* prev=dummy;
            while(prev->next!=nullptr && prev->next->val<temp->val){
                prev=prev->next;
            }
            temp->next=prev->next;
            prev->next=temp;
            temp=c;
        }
        return dummy->next;
    }
};