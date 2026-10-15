class SmallestInfiniteSet {
public:
    unordered_set<int> s;
    priority_queue<int,vector<int>,greater<int>> pq;
    int curr=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!pq.empty() && pq.top()<curr){
            int ans=pq.top();
            pq.pop();
            s.erase(ans);
            return ans;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num<curr && !s.count(num)){
            pq.push(num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */