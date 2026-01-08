class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, {p[0], p[1]}});
        }

        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
