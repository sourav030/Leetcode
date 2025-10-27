class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = ans.back();
            if (intervals[i][0] <= last[1]) {
                // Merge intervals
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
