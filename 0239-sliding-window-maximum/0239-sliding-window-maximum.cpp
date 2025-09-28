class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            // remove indices out of window
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            // window size >= k → record max
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
