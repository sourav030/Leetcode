class LRUCache {
public:
    int capacity;
    list<pair<int,int>> cache; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto it = mp[key];
        int value = it->second;

        // Move this node to the front (most recently used)
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }
    
    void put(int key, int value) {
        // If key already exists → remove old entry
        if(mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        // If at capacity → remove least recently used
        else if(cache.size() == capacity) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        // Insert new key-value pair at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
