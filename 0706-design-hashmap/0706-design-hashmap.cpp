class MyHashMap {
private:
    const int SIZE = 1009;
    vector<vector<pair<int, int>>> hashMap;

public:
    MyHashMap() {
        hashMap.resize(SIZE);
    }

    int hash(int key){
        return key % SIZE;
    }
    
    void put(int key, int value) {
        int location = hash(key);

        for(auto &it: hashMap[location]) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }

        hashMap[location].push_back({key, value});
    }
    
    int get(int key) {
        int location = hash(key);

        for(const auto &it: hashMap[location]) {
            if(it.first == key) {
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int location = hash(key);
        
        for(int i = 0; i < hashMap[location].size(); i++) {
           if(hashMap[location][i].first == key) {
            hashMap[location].erase(hashMap[location].begin() + i);
            break;
           }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */