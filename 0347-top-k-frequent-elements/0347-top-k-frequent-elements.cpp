class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;

        for (auto &ele : mp) {
            pq.push({ele.second, ele.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
