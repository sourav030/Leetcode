#include<bits/stdc++.h>
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int lsum=0;
        int rsum=0;
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
       
        for(int i=0; i<nums.size(); i++){
            left[i]=lsum;
            right[n-i-1]=rsum;
            rsum+=nums[n-i-1];
            lsum+=nums[i];
        }
        vector<int>ans;
        n=left.size();
        for(int i=0; i<n;i++){
            int ele=abs(left[i]-right[i]);
            ans.push_back(ele);
        }
        return ans;
        

    }
};