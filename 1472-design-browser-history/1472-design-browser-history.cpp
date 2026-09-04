class Node{
public:
    string url;
    Node* next;
    Node* prev;
    Node(string url){
        this->url=url;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newnode= new Node(url);
        curr->next=newnode;
        newnode->prev=curr;
        curr=newnode;
    }
    
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps>0 && curr->next!=nullptr){
            curr=curr->next;
            steps--;
        }
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