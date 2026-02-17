class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int left=0;
        int right=0;
        vector<int>ans;
        while(right<nums.size()){
            pq.push({nums[right],right});
            while(pq.top().second<left){
                pq.pop();
            }
            if(right-left+1==k and pq.top().second>=left){
                ans.push_back(pq.top().first);
                left++;
            }
            right++;

        }
        return ans;

    }
};