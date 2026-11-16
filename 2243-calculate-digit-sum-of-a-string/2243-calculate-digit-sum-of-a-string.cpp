class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            
            int n=s.size();
            int i=0;
            string change="";
            while(i<n){
                int num=0;
                for(int j = i; j < min(i + k, n); j++) {
                    num += s[j] - '0';
                }
                change+=to_string(num);
                i+=k;
            }
            s=change;
        }
        return s;
    }
};