class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            auto edge=graph[i];
            outdegree[i]=edge.size();
            if(outdegree[i]==0){
                st.insert(i);
            }
        }
        bool changed = true;

        while(changed) {
            changed = false;

            for(int i = 0; i < n; i++) {
                if(st.count(i)) continue;

                bool found = true;

                for(int j = 0; j < graph[i].size(); j++) {
                    if(!st.count(graph[i][j])) {
                        found = false;
                        break;
                    }
                }

                if(found) {
                    st.insert(i);
                    changed = true;
                }
            }
        }

        for(auto x : st) {
            ans.push_back(x);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};