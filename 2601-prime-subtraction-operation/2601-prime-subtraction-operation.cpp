class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        vector<bool> isprime(n+1,true);
        if (n >= 0) isprime[0] = false;
        if (n >= 1) isprime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        vector<int> primes;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                primes.push_back(i);
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1])
                continue;

            int diff = nums[i] - nums[i + 1];

            // Need smallest prime > diff
            auto it = upper_bound(primes.begin(), primes.end(), diff);

            if (it == primes.end())
                return false;

            if (*it >= nums[i])
                return false;
                
            nums[i] -= *it;

            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};