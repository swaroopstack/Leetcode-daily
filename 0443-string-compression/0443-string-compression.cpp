class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, ans=0;
        int n=chars.size();

        while(i<n){
            char c=chars[i];
            int cnt=0;

            while(i<n && chars[i]==c){
                cnt++;
                i++;
            }

            chars[ans++]=c;

            if(cnt>1){
                string s=to_string(cnt);

                for(char x:s){
                    chars[ans++]=x;
                }
            }
        }

        return ans;
    }
};