class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Step 1: Sort by start time (optional: can sort by end also)
        sort(points.begin(), points.end());

        // Step 2: Use merged intervals
        vector<vector<int>> merged;
        merged.push_back(points[0]);

        for (int i = 1; i < points.size(); i++) {
            vector<int>& last = merged.back();

            // Check for overlap
            if (points[i][0] <= last[1]) {
                // Merge the intervals (intersection is better here)
                last[0] = max(last[0], points[i][0]); // updated start
                last[1] = min(last[1], points[i][1]); // updated end
            } else {
                // No overlap, push as new group
                merged.push_back(points[i]);
            }
        }

        // Number of merged groups = number of arrows needed
        return merged.size();
    }
};
