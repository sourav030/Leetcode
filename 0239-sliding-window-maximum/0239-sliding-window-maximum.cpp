class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int start = 0;
        int end = 0;

        while (end < nums.size()) {
           
            pq.push({nums[end], end});

      
            if (end - start + 1 == k) {
              
                while (!pq.empty() && pq.top().second < start) {
                    pq.pop();
                }

               
                ans.push_back(pq.top().first);

            
                start++;
            }

           
            end++;
        }

        return ans;
    }
};
