class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        const long long BASE = 256;
        const long long MOD = 1e9 + 7;
        for (int len = 1; len <= n / 2; len++) {

            // Length must divide the whole string
            if (n % len != 0)
                continue;

            // Hash of the pattern
            long long patternHash = 0;

            for (int i = 0; i < len; i++) {
                patternHash =
                    (patternHash * BASE + s[i]) % MOD;
            }

            bool valid = true;

            // Check every block of length 'len'
            for (int start = len; start < n; start += len) {

                long long windowHash = 0;

                for (int j = start; j < start + len; j++) {
                    windowHash =
                        (windowHash * BASE + s[j]) % MOD;
                }

                // Hash doesn't match pattern
                if (windowHash != patternHash) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return true;
        }

        return false;
    }
};