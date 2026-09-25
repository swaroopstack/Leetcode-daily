class MyLinkedList {
public:
    class Node {
    public:
        // int key;
        int val;
        // Node* prev;
        Node* next;
        Node(int v) {
            val = v;
            next = NULL;
        }
    };
    Node* dummy;
    MyLinkedList() {
        dummy=new Node(0);

    }
    
    int get(int index) {
        int i=0;
        if(dummy->next==nullptr){
            return -1;
        }
        Node* temp=dummy->next;
        while(temp!=nullptr){
            if(i==index){
                return temp->val;
            }
            i++;
            temp=temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* first=dummy->next;
        Node* newnode=new Node(val);
        dummy->next=newnode;
        newnode->next=first;
    }
    
    void addAtTail(int val) {
        Node* temp=dummy;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* newnode=new Node(val);
        temp->next=newnode;
    }
    
    void addAtIndex(int index, int val) {
        int i=0;
        Node* temp=dummy;
        while(temp!=nullptr){
            if(i==index){
                Node* nextn=temp->next;
                Node* newnode=new Node(val);
                temp->next=newnode;
                newnode->next=nextn;
                return;
            }
            i++;
            temp=temp->next;
        }
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        Node* temp=dummy;
        while(temp->next!=nullptr){
            if(i==index){
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                return;
            }
            i++;
            temp=temp->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */