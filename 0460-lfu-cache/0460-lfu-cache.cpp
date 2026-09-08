class LFUCache {
public:
    int minfreq,cap;
    unordered_map<int,pair<int,int>> mp;
    unordered_map<int,list<int>> freq;
    unordered_map<int,list<int>::iterator> pos;
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int val=mp[key].first;
        int f=mp[key].second;
        freq[f].erase(pos[key]);
        if(freq[f].empty() && minfreq==f){
            minfreq++;
        }
        f++;
        mp[key].second=f;
        freq[f].push_front(key);
        pos[key]=freq[f].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            get(key);
            return;
        }
        if(mp.size()==cap){
            int oldfreq=freq[minfreq].back();
            freq[minfreq].pop_back();
            mp.erase(oldfreq);
            pos.erase(oldfreq);
        }
        mp[key]={value,1};
        freq[1].push_front(key);
        pos[key]=freq[1].begin();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */