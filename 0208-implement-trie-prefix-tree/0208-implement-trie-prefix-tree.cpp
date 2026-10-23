class Node{
public:
    Node* links[26]{};
    bool flag=false;
};
class Trie {
    Node* root;
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(char c: word){
            int index=c-'a';
            if(node->links[index]==nullptr){
                node->links[index]=new Node();
            }
            node=node->links[index];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(char c: word){
            int idx=c-'a';
            if(node->links[idx]==nullptr){
                return false;
            }
            node=node->links[idx];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char c: prefix){
            int idx=c-'a';
            if(node->links[idx]==nullptr){
                return false;
            }
            node=node->links[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */