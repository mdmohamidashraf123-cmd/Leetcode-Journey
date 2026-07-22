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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        int a=pow(2,c-1);
        int ans=0;
        temp=head;
        while(temp){
            ans+=a*(temp->val);
            a/=2;
            temp=temp->next;
        }
        return ans;
    }
};