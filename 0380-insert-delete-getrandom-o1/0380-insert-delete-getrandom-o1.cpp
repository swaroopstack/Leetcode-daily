class RandomizedSet {
public:
    vector<int> values;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        values.push_back(val);
        mp[val]=values.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int idx = mp[val];
        int last=values.back();
        values[idx]=last;
        mp[last]=idx;
        values.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand() % values.size();
        return values[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */