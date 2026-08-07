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
        int psum=0;
        //in t.c O(n)
        ListNode* temp=head;
        ListNode* dn=new ListNode(0);
        dn->next=head;
        unordered_map<int,ListNode*>m;
        temp=dn;
        while(temp){
          psum+=temp->val;
          m[psum]=temp;
          temp=temp->next;
        }
        temp=dn;
        psum=0;
        while(temp){
            psum+=temp->val;
            temp->next=m[psum]->next;
            temp=temp->next;
        }
        return dn->next;
    }
};