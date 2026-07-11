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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* temp=head;
        vector<int>a;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        int st=0;
        int end=a.size()-1;
        while(st<=end){
            if(a[st]!=a[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
        
    }
};