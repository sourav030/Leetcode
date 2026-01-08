class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int start=0;
        int end=0;
        vector<int>ans;
        while(end<nums.size()){
            pq.push({nums[end],end});
            while( !pq.empty() and pq.top().second<start){
                pq.pop();
            }
            if(end-start+1==k){
                ans.push_back(pq.top().first);
                start++;
            }
            end++;
        }
        return ans;
    }
};