class Trie{
public:
    Trie* links[26]{};
    vector<string> suggestions;
};
Trie* root;

void insert(string word){
    Trie* node=root;
    for(char c:word){
        int idx=c-'a';
        if(!node->links[idx]){
            node->links[idx]=new Trie();
        }
        node=node->links[idx];
        if(node->suggestions.size()<3){
            node->suggestions.push_back(word);
        }
    }
}

void search(string word,vector<vector<string>>& ans){
    Trie* node=root;
    bool found=true;
    for(char c:word){
        int idx=c-'a';
        if(!found || !node->links[idx]){
            found=false;
            ans.push_back({});
            continue;
        }
        node=node->links[idx];
        ans.push_back(node->suggestions);
    }
}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root=new Trie();
        sort(products.begin(),products.end());
        for(string s:products){
            insert(s);
        }
        vector<vector<string>> ans;
        search(searchWord,ans);
        return ans;
    }
};