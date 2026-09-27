class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int> portal(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                portal[i]=st.top();
                portal[st.top()]=i;
                st.pop();
            }
        }
        string ans="";
        int i=0;
        int dir=1;
        while(i>=0 && i<n){
            if(s[i]=='(' || s[i]==')'){
                i=portal[i];
                dir=-dir;
            }
            else{
                ans+=s[i];
            }
            i+=dir;
        }
        return ans;
    }
};