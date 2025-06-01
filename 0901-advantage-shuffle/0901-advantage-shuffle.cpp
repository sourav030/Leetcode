class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>>q;
        for(int i=0; i<nums2.size(); i++){
            q.push({nums2[i],i});
        }
        int start=0;
        int end=nums1.size()-1;
        vector<int>ans(nums1.size(),-1);
        while(!q.empty()){
            if(nums1[end]>q.top().first){
                ans[q.top().second]=nums1[end];
                end--;
                q.pop();
            }
            else{
                ans[q.top().second]=nums1[start];
                start++;
                q.pop();
            }
        }
        return ans;
    }
};