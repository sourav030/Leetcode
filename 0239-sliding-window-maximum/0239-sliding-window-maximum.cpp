class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         priority_queue<pair<int,int>>pq;
         int end=0;
         int start=0;
         vector<int>ans;
         while(end<nums.size()){
            pq.push({nums[end],end});
            if(end-start+1==k){
                while(!pq.empty() and pq.top().second<start){
                    pq.pop();
                }
                start++;
                ans.push_back(pq.top().first);
            }
            end++;
         }
         return ans;
    }
};