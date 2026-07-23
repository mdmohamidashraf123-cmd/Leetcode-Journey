/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dn=new Node(-1);
        Node* b;
        if(!head){
            return nullptr;
        }
        if(!head->next){
            dn->next=new Node(head->val);
            b=dn->next;
            if(head->random){
                b->random=dn->next;
            }else{
                b->random=nullptr;
            }
            return b;
        }
        Node* temp=head;
        Node* c=temp;
        unordered_map<Node*,Node*>q;
        temp=head;
        c=dn;
        Node* y;
        while(temp){
            y=new Node(temp->val);
            q[temp]=y;
            c->next=y;
            c=c->next;
            temp=temp->next;
        }
        c->next=nullptr;
        c=dn->next;
        temp=head;
        while(c){
            c->random=q[temp->random];
            c=c->next;
            temp=temp->next;
        }
        return dn->next;
    }
};