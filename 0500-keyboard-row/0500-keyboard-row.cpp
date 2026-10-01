class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        set<char> row3 = {'z','x','c','v','b','n','m'}; 
        vector<string> ans;
        for(string s:words){
            bool first=false;
            bool second=false;
            bool third=false;
            for(char c:s){
                c=tolower(c);
                if(row1.count(c)){
                    first=true;
                }
                else if(row2.count(c)){
                    second=true;
                }
                else if(row3.count(c)){
                    third=true;
                }
            }
            if(first+second+third==1){
                ans.push_back(s);
            }
        }
        return ans;
    }
};