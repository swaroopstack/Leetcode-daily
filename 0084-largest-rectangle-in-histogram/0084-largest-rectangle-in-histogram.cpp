class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int w=nse-pse-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            int w=nse-pse-1;
            ans=max(ans,h*w);
        }
        return ans;
    }
};