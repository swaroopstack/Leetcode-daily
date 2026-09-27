class Solution {
public:
    vector<string> ans;
    bool valid(string s){
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(st.top()=='('){
                    st.pop();
                }
            }
        }
        return st.empty();
    }
    void solve(string curr,int n){
        if(curr.size()==2*n){
            if(valid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
    }
    vector<string> generateParenthesis(int n) {
        solve("",n);
        return ans;
    }
};