class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int m = 10;
        vector<string> ans;
        if (n < m) {
            return ans;
        }
        const long long base = 256;
        const long long mod = 1e9 + 7;
        unordered_set<long long> seen;
        unordered_set<string> added;
        unordered_set<string> appeared;
        long long hash = 0;
        long long power = 1;
        for (int i = 1; i < m; i++) {
            power = (power * base) % mod;
        }
        for (int i = 0; i < m; i++) {
            hash = (hash * base + s[i]) % mod;
        }
        seen.insert(hash);
        appeared.insert(s.substr(0, m));

        for (int i = 1; i <= n - m; i++) {

            hash = (hash - s[i - 1] * power) % mod;
            if (hash < 0) {
                hash += mod;
            }
            hash = (hash * base + s[i + m - 1]) % mod;

            string curr = s.substr(i, m);
            if (seen.count(hash)) {

                if (appeared.count(curr) && added.insert(curr).second) {
                    ans.push_back(curr);
                }
            }
            seen.insert(hash);
            appeared.insert(curr);
        }
        return ans;
    }
};