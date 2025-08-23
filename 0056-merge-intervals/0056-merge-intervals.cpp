class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int>a=intervals[i];
            vector<int>b=ans.back();
            if(b[1]>=a[0]){
                b[0]=min(b[0],a[0]);
                b[1]=max(b[1],a[1]);
                ans.pop_back();
                ans.push_back(b);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};