class Node{
public:
    Node* links[26]{};
    bool flag=false;
}; 
class StreamChecker {
public:
    Node* root;
    string stream;
    StreamChecker(vector<string>& words) {
        root=new Node();
        for(string word: words){
            Node* node=root;
            for(int i=word.size()-1;i>=0;i--){
                int idx=word[i]-'a';

                if(node->links[idx]==nullptr){
                    node->links[idx]=new Node();
                }
                node=node->links[idx];
            }
            node->flag=true;
        }
    }
    
    bool query(char letter) {
        stream+=letter;
        Node* node=root;
        for(int i=stream.size()-1;i>=0;i--){
            int idx=stream[i]-'a';
            if(node->links[idx]==nullptr){
                return false;
            }
            node=node->links[idx];
            if(node->flag){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */