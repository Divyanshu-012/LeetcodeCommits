class LFUCache {
public:
    int cap;
    int size ;

    unordered_map<int,list<vector<int>>::iterator>mp; // key -> Address

    map<int,list<vector<int>>>freq; //counter -> {key,val,count}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;

    }

    void makeMostFU(int key){
        auto &vec = *(mp[key]);

        int value = vec[1];
        int f = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty())
           freq.erase(f);

        f++;
        freq[f].push_front({key,value,f});

        mp[key]= freq[f].begin();

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        auto vec = *(mp[key]);
        int value = vec[1];

        makeMostFU(key);
        return value;

    }
    
    void put(int key, int value) {
    if(cap == 0) return;

    if(mp.find(key) != mp.end()) {
        auto &vec = *(mp[key]);
        vec[1] = value;
        makeMostFU(key);
    } else {
        if(size == cap) {
            // Evict least frequently used
            auto &lfu_list = freq.begin()->second;  // use reference
            int key_to_delete = lfu_list.back()[0];
            lfu_list.pop_back();
            if(lfu_list.empty()) freq.erase(freq.begin()->first);
            mp.erase(key_to_delete);
            size--;
        }
        // Insert new key
        freq[1].push_front({key,value,1});
        mp[key] = freq[1].begin();
        size++;
    }
}

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */