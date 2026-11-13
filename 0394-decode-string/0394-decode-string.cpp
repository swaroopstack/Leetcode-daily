class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for(int i=0; i<s.size(); i++){

            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }

            else if(s[i]=='['){
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            else if(s[i]==']'){
                int k = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                string temp = curr;

                while(k--){
                    prev += temp;
                }

                curr = prev;
            }

            else{
                curr += s[i];
            }
        }

        return curr;
    }
};