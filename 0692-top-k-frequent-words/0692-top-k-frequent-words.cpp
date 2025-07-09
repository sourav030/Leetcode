#define P pair<int, string>

struct cmp {
    bool operator()(P& a, P& b) {
        if (a.first == b.first)
            return a.second < b.second; // max lexical first in min-heap
        return a.first > b.first;       // min frequency at top
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }

        priority_queue<P, vector<P>, cmp> pq;

        for (auto& entry : mp) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
