class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            int endTime = intervals[i][1];
            int idx = -1;
            int minStart = INT_MAX;
            for(int j = 0; j < n; j++) {
                int startTime = intervals[j][0];
                if(startTime >= endTime && startTime < minStart) {
                    minStart = startTime;
                    idx = j;
                }
            }
            ans.push_back(idx);
        }
        return ans;
    }
};
