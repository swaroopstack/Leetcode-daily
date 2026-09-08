class Solution {
public:
    unordered_map<int,string> mp{
        {1,""},
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };
    void solve(string digits,int i,string temp,vector<string>& ans){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        string s=mp[digits[i]-'0'];
        for(int j=0;j<s.size();j++){
            temp.push_back(s[j]);
            solve(digits,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        solve(digits,0,temp,ans);
        return ans;
    }
};