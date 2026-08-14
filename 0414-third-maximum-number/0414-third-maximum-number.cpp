class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()==1){
            return nums[0];
        }
        if(s.size()==2){
            return *s.rbegin();
        }
        auto it =next(s.begin(),s.size()-3);
        return *it;
    }
};