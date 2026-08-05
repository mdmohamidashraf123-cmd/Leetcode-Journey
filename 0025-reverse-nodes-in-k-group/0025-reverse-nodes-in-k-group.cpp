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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*>s;
        ListNode* temp=head;
        int c=0;
        int a=0;
        ListNode* x;
        while(temp){
           a++;
           temp=temp->next;
        }
        temp=head;
        while(temp && c<k){
          c++;
          if(c==k){
            x=temp;
          }
          temp=temp->next;
        }
        int z=a-k;
        if(z/k<1){
            s.push_back(temp);
        }
        c=0;
        while(temp && z/k>=1){
            c++;
            if(c==k){
                s.push_back(temp);
                z=z-c;
                c=0;
            }
            temp=temp->next;
            if(z/k<1){
                s.push_back(temp);
            }
        }
        c=0;
        temp=head;
        int i=0;
        ListNode* prev=s[i];
        while(temp){
            c++;
            ListNode* d=temp->next;
            temp->next=prev;
            prev=temp;
            temp=d;
            if(c==k){
               c=0;
               i++;
               if(i==s.size()){
                break;
               }
               prev=s[i];
            }
        }
        head=x;
        return head;
    }
};