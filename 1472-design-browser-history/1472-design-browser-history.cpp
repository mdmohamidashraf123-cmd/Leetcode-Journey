class BrowserHistory {
public:
 class Node{
    public:
    string s;
    Node* next;
    Node* prev;
    public:
    Node(string k, Node* next1, Node* prev1){
        s=k;
        next=next1;
        prev=prev1;
    }
    Node(string k){
        s=k;
        next=nullptr;
        prev=nullptr;
    }
 }; 
    Node* temp;
    BrowserHistory(string homepage) {
        temp=new Node(homepage);
        
    }
    // Node* temp=head;
    void visit(string url) {
        temp->next=new Node(url);
        Node* a=temp;
        temp=temp->next;
        temp->prev=a;
    }
    
    string back(int steps) {
        string ans=temp->s;
        for(int i=0;i<steps;i++){
            if(temp && temp->prev){
            temp=temp->prev;
            ans=temp->s;
            }else{
                break;
            }
        }
        return ans;
    }
    
    string forward(int steps) {
        string ans=temp->s;
        for(int i=0;i<steps;i++){
            if(temp &&temp->next){
             temp=temp->next;
             ans=temp->s;
            }else{
                break;
            }
        }
        return ans ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */