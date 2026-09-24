class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int div=nums.size()/2;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        if(mp.size()==nums.size()){
            return false;
        }
        int pairs=0;
        for(auto &it:mp){
            if(it.second%2==0){
                int freq=it.second;
                pairs+=(freq/2);
            }
        }
        if(pairs==div){
            return true;
        }
        return false;
    }
};