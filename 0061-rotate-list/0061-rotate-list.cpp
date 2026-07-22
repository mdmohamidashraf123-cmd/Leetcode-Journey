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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int c=0;
        int a=0;
        if(!head ||! head->next){
            return head;
        }
        while(temp){
            c++;
            temp=temp->next;
        }
        k=k%c;
        if(k==0){
            return head;
        }
        temp=head;
        while(temp){
            a++;
            if(a==c-k){
                break;
            }
            temp=temp->next;
        }
        ListNode* x=head;
        while(x->next){
            x=x->next;
        }
        x->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};