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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<ListNode*,int>m;
        ListNode* temp=head;
        int n=nums.size();
        while(temp){
         for(int i=0;i<n;i++){
            if(nums[i]==temp->val){
                m[temp]++;
                break;
            }
         }
         temp=temp->next;
        }
        temp=head;
        int s=0;
        while(temp){
            if(m[temp]==1){
                ListNode* a=temp->next;
                while(a && m[a]==1){
                    a=a->next;
                }
                s++;
                if(a && a->next){
                    temp=a->next;
                }else{
                    break;
                }
            }else{
                temp=temp->next;
            }
        }
        return s;
    }
};