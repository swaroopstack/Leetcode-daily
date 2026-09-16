class Solution {
public:
    string interpret(string command) {
        string ans;
        int i=0;
        while(i<command.size()){
            if(command[i]=='G'){
                ans.push_back(command[i]);
                i++;
            }
            else if(command[i]=='('){
                if(command[i+1]=='a'){
                    ans.push_back(command[i+1]);
                    ans.push_back(command[i+2]);
                    i+=4;
                }
                else{
                    ans.push_back('o');
                    i+=2;
                }
            }
        }
        return ans;
    }
};