class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(),[](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int>&a=ans.back();
            if(a[1]>intervals[i][0]){
               count++;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return count;
    }
};