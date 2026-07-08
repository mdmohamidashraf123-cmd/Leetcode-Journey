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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* list3=nullptr;
        if(list1==list3){
            return list2;
        }else if(list2==list3){
            return list1;
        }
        ListNode* head=nullptr;
        if (list1->val >list2->val ){
            head=list2;
            temp2=temp2->next;
        }else{
            head=list1;
            temp1=temp1->next;
        }
        ListNode* prev=head;
        while(temp1 && temp2){
            if(temp1->val >temp2->val){
                prev->next=temp2;
                temp2=temp2->next;
            }else{
                prev->next=temp1;
                temp1=temp1->next;
            }
            prev=prev->next;
        }
        if(temp2){
            prev->next=temp2;
        }
        if(temp1){
            prev->next=temp1;
        }
    
        return head;
    }
};