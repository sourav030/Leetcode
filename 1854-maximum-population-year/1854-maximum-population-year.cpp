class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPop = 0, year = 1950;

        for (int y = 1950; y <= 2050; y++) {
            int curr = 0;
            for (auto &log : logs) {
                if (log[0] <= y && y < log[1]) {
                    curr++;
                }
            }
            if (curr > maxPop) {
                maxPop = curr;
                year = y;
            }
        }
        return year;
    }
};