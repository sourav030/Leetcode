class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        for(int i=0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        int n=nums1.size();
        vector<vector<int>>ans;
        map<int,vector<int>>mp;
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i][0]].push_back(nums1[i][1]);
        }

        for(auto ele: mp){
            int id=ele.first;
            int val=0;
            for(int i: ele.second){
                val+=i;
            }
            ans.push_back({id,val});
        }
        
        return ans;
    }
};