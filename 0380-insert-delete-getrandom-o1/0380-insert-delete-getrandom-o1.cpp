class RandomizedSet {
public:
    unordered_map<int,int> mp; // val -> index in nums
    vector<int> nums;

    RandomizedSet() {}

    bool insert(int val) {
        if(mp.count(val)) return false;  // already exists
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(!mp.count(val)) return false;

        int last = nums.back();
        int idx = mp[val];

        // swap val with last element
        nums[idx] = last;
        mp[last] = idx;

        // remove val
        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};
