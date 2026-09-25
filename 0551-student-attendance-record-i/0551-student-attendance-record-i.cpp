class Solution {
public:
    bool checkRecord(string s) {
        int count=0;
        int ab=0;
        for(char x:s){
            if(count>=3){
                return false;
            }
            if(x=='A'){
                ab++;
                count=0;
            }
            else if(x=='L'){
                count++;
            }
            else{
                count=0;
            }
        }
        if(count>=3 || ab>=2){
            return false;
        }
        return true;
    }
};