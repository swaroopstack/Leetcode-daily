class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n=spells.size();
        int m=potions.size();
        for(int x: spells){
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(1ll*potions[mid]*x>=success){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            ans.push_back(m-low);
        }
        return ans;
    }
};