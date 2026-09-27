class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        for(char c: password){
            st.insert(c);
        }
        int score=0;
        for(auto &it : st){
            if(isdigit(it)){
                score+=3;
            }
            else if(islower(it)){
                score+=1;
            }
            else if(isupper(it)){
                score+=2;
            }
            else{
                score+=5;
            }
        }
        return score;
    }
};