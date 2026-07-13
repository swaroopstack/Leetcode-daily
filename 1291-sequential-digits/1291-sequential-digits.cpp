class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int length=2;length<=9;length++){
            for(int start=1;start<=10-length;start++){
                int num=0;
                int digit=start;
                for(int i=0;i<length;i++){
                    num=num*10+digit;
                    digit++;
                }
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};