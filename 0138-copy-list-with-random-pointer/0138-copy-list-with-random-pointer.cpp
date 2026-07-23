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
        unordered_map<Node*,int>q;
        int a=0;
        while(temp){
            while(c){
                a++;
                if(c==temp->random){
                  q[temp]=a;
                  break;
                }else{
                    q[temp]=a+1;
                }
                c=c->next;
            }
            c=head;
            a=0;
            temp=temp->next;
        }
        temp=head;
        c=dn;
        Node* y;
        while(temp){
            y=new Node(temp->val);
            c->next=y;
            c=c->next;
            temp=temp->next;
        }
        c->next=nullptr;
        b=dn->next;
        c=dn->next;
        temp=head;
        a=0;
        // b=head;
        while(c){
            while(b){
                a++;
                if(a==q[temp]){
                    c->random=b;
                    break;
                }else{
                    c->random=nullptr;
                }
                b=b->next;
            }
            a=0;
            b=dn->next;
            c=c->next;
            temp=temp->next;
        }
        return dn->next;
    }
};