class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int sz=min(prices.size(),discounts.size());
        double ans=0.0;
        for(int i=0;i<sz;i++){
            ans+=prices[i]*(100.0-discounts[i])/100.0;
        }
        for(int i=sz;i<prices.size();i++){
            ans+=prices[i];
        }
        return ans;
    }
};