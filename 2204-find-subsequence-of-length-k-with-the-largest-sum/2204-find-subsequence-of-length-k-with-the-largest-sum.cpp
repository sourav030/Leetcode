class Solution {
public:
   typedef pair<int, int> P;

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P,vector<P>, greater<P>>pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<P>arr;
        while(!pq.empty()){
            arr.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};