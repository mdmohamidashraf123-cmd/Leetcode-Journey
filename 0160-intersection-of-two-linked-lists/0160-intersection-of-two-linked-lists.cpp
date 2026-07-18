/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        while(tempa){
            while(tempb){
             if(tempa==tempb){
                return tempa;
             }
             tempb=tempb->next;
            }
            tempb=headB;
            tempa=tempa->next;
        }
        return nullptr;
    }
};