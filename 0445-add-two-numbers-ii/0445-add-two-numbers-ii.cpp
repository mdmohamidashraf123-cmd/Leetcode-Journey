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
        stack<int>s1;
        stack<int>s2;
        while(temp){
            s1.push(temp->val);
            temp=temp->next;
        }
        while(t){
            s2.push(t->val);
            t=t->next;
        }
        int sum=0;
        ListNode* dn=new ListNode(-1);
        ListNode* a =dn;
        while(!s1.empty() && !s2.empty()){
            sum+=s1.top() + s2.top();
            s1.pop();
            s2.pop();
            a->next=new ListNode(sum%10);
            a=a->next;
            sum=sum/10;
        }
        while(!s1.empty()){
            sum+=s1.top();
            s1.pop();
            a->next=new ListNode(sum%10);
            a=a->next;
            sum/=10;
        }
        while(!s2.empty()){
            sum+=s2.top();
            s2.pop();
            a->next=new ListNode(sum%10);
            a=a->next;
            sum/=10;
        }
        if(sum>0){
            a->next=new ListNode(sum%10);
            a=a->next;
        }
        a=dn->next;
        prev=nullptr;
        while(a){
            ListNode* c=a->next;
            a->next=prev;
            prev=a;
            a=c;
        }
        return prev;
    }
};