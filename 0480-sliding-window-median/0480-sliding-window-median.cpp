class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        unordered_map<int, int> delayed;
        unordered_map<int, bool> inLeft;

        priority_queue<pair<int,int>, vector<pair<int,int>>> left;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > right;

        int i = 0, j = 0;
        int leftsize = 0;
        int rightsize = 0;

        auto clean = [&]() {

            while (!left.empty() &&
                   delayed[left.top().second] > 0) {

                delayed[left.top().second]--;
                left.pop();
            }

            while (!right.empty() &&
                   delayed[right.top().second] > 0) {

                delayed[right.top().second]--;
                right.pop();
            }
        };

        while (j < nums.size()) {

            // Insert
            if (left.empty() || nums[j] <= left.top().first) {
                left.push({nums[j], j});
                inLeft[j] = true;
                leftsize++;
            }
            else {
                right.push({nums[j], j});
                inLeft[j] = false;
                rightsize++;
            }

            // Balance
            if (leftsize > rightsize + 1) {

                auto p = left.top();
                left.pop();

                right.push(p);

                inLeft[p.second] = false;

                leftsize--;
                rightsize++;
            }
            else if (leftsize < rightsize) {

                auto p = right.top();
                right.pop();

                left.push(p);

                inLeft[p.second] = true;

                rightsize--;
                leftsize++;
            }

            // Remove invalid elements from top
            clean();

            // Window size = k
            if (j - i + 1 == k) {

                // Get median
                if (k % 2 == 0) {
                    double med =
                        ((double)left.top().first +
                         (double)right.top().first) / 2.0;

                    ans.push_back(med);
                }
                else {
                    ans.push_back((double)left.top().first);
                }

                // Mark nums[i] for deletion
                delayed[i]++;

                // Decrease logical size of correct heap
                if (inLeft[i]) {
                    leftsize--;
                }
                else {
                    rightsize--;
                }

                i++;

                // Remove marked elements that reached the top
                clean();

                // Balance after removal
                if (leftsize > rightsize + 1) {

                    auto p = left.top();
                    left.pop();

                    right.push(p);

                    inLeft[p.second] = false;

                    leftsize--;
                    rightsize++;
                }
                else if (leftsize < rightsize) {

                    auto p = right.top();
                    right.pop();

                    left.push(p);

                    inLeft[p.second] = true;

                    rightsize--;
                    leftsize++;
                }
            }

            j++;
        }

        return ans;
    }
};