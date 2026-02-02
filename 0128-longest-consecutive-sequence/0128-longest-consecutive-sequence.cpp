class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 1;

        for(int x : s) {
           
            if(s.find(x - 1) == s.end()) {
                int count = 1;
                int curr = x;

                while(s.find(curr + 1) != s.end()) {
                    curr++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
