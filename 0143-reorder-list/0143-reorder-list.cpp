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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        ListNode* a=head;
        stack<ListNode*>s;
        while(temp){
            s.push(temp);
            temp=temp->next;
        }
        int c=0;
        while(a){
            if(a->next && a->next->next){
               ListNode* nn=a->next;
               a->next=s.top();
               s.top()->next=nn;
               s.pop();
               s.top()->next=nullptr;
               a=a->next->next;
            }else{
                break;
            }
        }
        
    }
};