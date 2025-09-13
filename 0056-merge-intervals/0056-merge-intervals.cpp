class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int i=1;
        while(i<intervals.size()){
            vector<int>&a=ans.back();
            // now at this we chek that endtime off this interval is greater our not
            // start time of another interval
            if(a[1]>=intervals[i][0]){
                a[0]=min(a[0],intervals[i][0]);
                a[1]=max(a[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};