#define P pair<double, pair<int,int>>

class Solution {
public:
    double find(int a ,int b){
        double result= sqrt(pow((a-0),2)+pow((b-0),2));
        return result;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0; i<points.size(); i++){
            double dis=find(points[i][0],points[i][1]);
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        vector<vector<int>>ans;
        while(!pq.empty() and k--){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            pq.pop();
            ans.push_back({a,b});
        }
        return ans;
    }
};