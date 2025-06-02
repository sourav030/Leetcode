class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int>a=ans.back();
            if(a[1]>=intervals[i][0]){
                a[0]=min(a[0],intervals[i][0]);
                a[1]=max(a[1],intervals[i][1]);
                ans.pop_back();
                ans.push_back(a);
            }
            else{
                ans.push_back(intervals[i]);
            }

        }
        return ans;
    }
};