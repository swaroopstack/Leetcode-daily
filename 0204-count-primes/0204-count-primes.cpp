class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);

        for(int i=2;i*i<=n;i++){
            if(isprime[i]==true){
                for(int j=2;i*j<=n;j++){
                    isprime[i*j]=false;
                }
            }
        } 
        int ans=0;
        for(int i=2;i<n;i++){
            if(isprime[i]==true){
                ans++;
            }
        }
        return ans;
    }
};