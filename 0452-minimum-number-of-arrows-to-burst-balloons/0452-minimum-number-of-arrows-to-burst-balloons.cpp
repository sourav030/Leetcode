class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });

        int arrow=1;
        int endTime=points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]>endTime){
                arrow++;
                endTime=points[i][1];
            }
        }
        return arrow;
    }
};