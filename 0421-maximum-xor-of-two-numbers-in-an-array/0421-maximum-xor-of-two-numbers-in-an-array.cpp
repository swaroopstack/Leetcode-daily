class Solution {
public:
    struct Node {
        Node* links[2] = {nullptr, nullptr};
    };

    Node* root = new Node();

    void insert(int num) {
        Node* node = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->links[bit])
                node->links[bit] = new Node();

            node = node->links[bit];
        }
    }

    int getMax(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (node->links[opposite]) {
                ans |= (1 << i);
                node = node->links[opposite];
            } else {
                node = node->links[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;

        for (int num : nums)
            insert(num);

        for (int num : nums)
            ans = max(ans, getMax(num));

        return ans;
    }
};