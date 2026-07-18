class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        long long ans=0;
        int left=0;
        int right= people.size()-1;
        sort(people.begin(),people.end());
        while(left<=right){
            if(left==right){
                ans++;
                break;
            }
            else if(people[left]+people[right]<=limit){
                ans++;
                left++;
                right--;
            }
            else{
                ans++;
                right--;
            }
        }
        return ans;
    }
};