class Solution {
public:
    int reverseDegree(string s) {
        int idx=1;
        int sum=0;
        for(int i=0;i<s.size();i++){
            int pro=idx*(123-s[i]);
            idx++;
            sum+=pro;
        }
        return sum;
    }
};