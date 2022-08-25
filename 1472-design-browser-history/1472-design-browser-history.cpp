class BrowserHistory {
public:
    class Node{
        public:
        string url;
        Node* next;
        Node* prev;
        Node(string url)
        {
            this->url=url;
            this->next=NULL;
            this->prev=NULL;
        }
    };
    Node* curr=NULL;
    BrowserHistory(string homepage) {
        Node* temp=new Node(homepage);
        curr=temp;
    }
    
    void visit(string url) {
        Node* temp=new Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr=temp;
    }
    
    string back(int steps) {
        Node* temp=curr;
        while(temp->prev)
        {
            if(steps>0)
                steps--;
            else
            {
                curr=temp;
                return curr->url;
            }
            temp=temp->prev;
        }
        curr=temp;
        return curr->url;
        
    }
    
    string forward(int steps) {
        Node* temp=curr;
        while(temp->next)
        {
            if(steps>0)
                steps--;
            else
            {
                curr=temp;
                return curr->url;
            }
            temp=temp->next;
        }
        curr=temp;
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */