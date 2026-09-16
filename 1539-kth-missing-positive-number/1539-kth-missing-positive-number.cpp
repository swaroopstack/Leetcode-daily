class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> miss;
        unordered_set<int> st;
        for(int x:arr){
            st.insert(x);
        }
        int end=arr.size();
        for(int i=1;i<arr[end-1];i++){
            if(!st.count(i)){
                miss.push_back(i);
            }
        }
        if(miss.size() >= k){
            return miss[k-1];
        }
        return arr[end-1] + (k - miss.size());
    }
};