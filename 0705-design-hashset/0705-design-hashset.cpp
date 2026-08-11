class MyHashSet {
public:
    vector<int> st;
    MyHashSet() {
        st.resize(1e6+7,-1);
    }
    
    void add(int key) {
        st[key]=1;
    }
    
    void remove(int key) {
        st[key]=-1;
    }
    
    bool contains(int key) {
        if(st[key]==-1){
            return false;
        }
        else{
            return true;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */