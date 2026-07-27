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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        ListNode*prev=nullptr;
        ListNode* t=l2;
        while(temp){
            ListNode* n=temp->next;
            temp->next=prev;
            prev=temp;
            temp=n;
        }
        ListNode* head1=prev;
        prev=nullptr;
        while(t){
            ListNode* n=t->next;
            t->next=prev;
            prev=t;
            t=n;
        }
        ListNode* head2=prev;
        temp=head1;
        t=head2;
        ListNode* dn=new ListNode(-1);
        ListNode* a=dn;
        int sum=0;
        while(temp && t){
            sum+=temp->val+t->val;
            a->next=new ListNode(sum%10);
            a=a->next;
            sum=sum/10;
            temp=temp->next;
            t=t->next;
        }
        while(temp){
            sum+=temp->val;
            a->next=new ListNode(sum%10);
            a=a->next;
            sum=sum/10;
            temp=temp->next;
        }
        while(t){
            sum+=t->val;
            a->next=new ListNode(sum%10);
            a=a->next;
            sum=sum/10;
            t=t->next;
        }
        if(sum>0){
            a->next=new ListNode(sum);
            a=a->next;
        }
        a->next=nullptr;
        ListNode* h= dn->next;
        prev=nullptr;
        while(h){
            ListNode* c=h->next;
            h->next=prev;
            prev=h;
            h=c;
        }
        return prev;
    }
};