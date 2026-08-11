class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(Node* curr) {
        Node* nextnode = curr->next;
        Node* prevnode = curr->prev;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    void addnode(Node* newnode) {
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* ans = mp[key];
            deletenode(ans);
            addnode(ans);
            return ans->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];

            curr->val = value;

            deletenode(curr);
            addnode(curr);

            return;
        }
        if (cap == mp.size()) {
            Node* temp = tail->prev;
            deletenode(temp);
            mp.erase(temp->key);
            delete temp;
        }
        Node* newnode = new Node(key, value);
        addnode(newnode);
        mp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */