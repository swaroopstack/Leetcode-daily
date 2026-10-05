class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        int open=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                open++;
            }
            else{
                open--;
                if(s[i-1]=='('){
                    score+=1<<open;
                }
            }
            if(open<0){
                open=0;
            }
        }

        return score;
    }
};