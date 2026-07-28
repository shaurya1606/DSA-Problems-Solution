class MyHashSet {
private: 
    int SIZE = 1009;
    vector<vector<int>> hashSet;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        hashSet.resize(SIZE);
    }
    
    void add(int key) {
        if(contains(key)) {
            remove(key);
        }

        int loc = hash(key);

    

        hashSet[loc].push_back(key);
    }
    
    void remove(int key) {
        int loc = hash(key);

        for(int i = 0; i < hashSet[loc].size(); i++) {
            if(hashSet[loc][i] == key) {
                hashSet[loc].erase(hashSet[loc].begin()+i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int loc = hash(key);

        for(int i = 0; i < hashSet[loc].size(); i++) {
            if(hashSet[loc][i] == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */