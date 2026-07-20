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
    ListNode* head=nullptr;
    ListNode* add(ListNode* prev,ListNode* a ,ListNode*b ,int &sum ){
        if(!a && !b){
            if(sum>0){
                ListNode* nn=new ListNode(sum);
                prev->next=nn;
            }
            return head;
        }
        if(a && b){
        sum+=a->val + b->val;
        }else if(!a){
            sum+=b->val;
        }else if(!b){
            sum+=a->val;
        }
        ListNode* nn=new ListNode(sum%10);
        sum=sum/10;
        if(!prev){
            head=nn;
        }else{
            prev->next=nn;
        }
        prev=nn;
        ListNode* z;
        if(a && b){
           z=add(prev,a->next ,b->next,sum );
        }else if(!a){
            z=add(prev,a,b->next,sum );
        }else{
            z=add(prev,a->next ,b,sum );
        }
        return z;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev=nullptr;
        ListNode* a=l1;
        ListNode* b=l2;
        int sum=0;
        ListNode* h=add(prev,a ,b ,sum );
        return h;
    }
};