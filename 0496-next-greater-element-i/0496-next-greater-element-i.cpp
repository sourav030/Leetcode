class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans(n,-1);
        for(int i = 0; i < nums1.size(); i++){
    bool found = false;
    for(int j = 0; j < nums2.size(); j++){
        if(nums2[j] == nums1[i]) {
            found = true;
        }
        else if(found && nums2[j] > nums1[i]) {
            ans[i] = nums2[j];
            break;
        }
    }
}

        return ans;
    }
};