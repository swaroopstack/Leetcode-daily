class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> followers;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<pair<int,int>> v;
        for(auto it : tweets[userId]){
            v.push_back(it);
        }
        for(auto it : followers[userId]){
            for(auto i : tweets[it]){
                v.push_back(i);
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].second);
            if(i==9){
                break;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */