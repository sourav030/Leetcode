class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> window;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
           
            if (nums[i] < 0)
                window.insert(nums[i]);

          
            if (i >= k) {
                if (nums[i - k] < 0) {
                    window.erase(window.find(nums[i - k]));
                }
            }

          
            if (i >= k - 1) {
                if (window.size() < x) {
                    ans.push_back(0);  
                } else {
                    auto it = window.begin();
                    advance(it, x - 1);  
                    ans.push_back(*it);
                }
            }
        }

        return ans;
    }
};
