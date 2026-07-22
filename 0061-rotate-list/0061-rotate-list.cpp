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
        ListNode* prev=nullptr;
        ListNode* nn;
        ListNode* b;
        int a=0;
        int q=0;
        if(!head || !head->next|| k==0){
           return head;
        }
        while(temp){
            q++;
            temp=temp->next;
        }
        k=k%q;
        if(k==0){
            return head;
        }
        temp=head;
        while(temp){
            
            nn=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nn;
        }
        head=prev;
        int c=0;
        temp=head;
        while(temp){
            a++;
            if(a==k+1){
              b=temp;
              break;
            }
            temp=temp->next;
        }
        prev=b;
        temp=head;
        ListNode* z=head;
        while(temp){
            c++;
            nn=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nn;
            if(c==k){
                break;
            }
        }
        nn=prev;
        prev=nullptr;
        head=nn;
        temp=b;
        while(temp){
            nn=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nn;
        }
        z->next=prev;
        return head;
    }
};