class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isprime(right + 1, true);
        if (right >= 0)
            isprime[0] = false;
        if (right >= 1)
            isprime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isprime[i] == true) {
                for (int j = 2; i * j <= right; j++) {
                    isprime[i * j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isprime[i] == true) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2) {
            return {-1, -1};
        }
        int ans = INT_MAX;
        for (int i = 0; i < primes.size() - 1; i++) {
            ans = min(ans, primes[i + 1] - primes[i]);
        }
        for (int i = 0; i < primes.size() - 1; i++) {
            if (ans == (primes[i + 1] - primes[i])) {
                return {primes[i], primes[i + 1]};
            }
        }
        return {-1, -1};
    }
};