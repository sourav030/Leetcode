class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>vec;
        int n=start.size();
        
        for(int i=0; i<n; i++){
            vec.push_back(make_pair(end[i],start[i]));
        }
       
        int ans=1;
        sort(vec.begin(),vec.end());
        int freeTime=vec[0].first;
        for(int i=1; i<n; i++){
            if(freeTime<vec[i].second){
                ans+=1;
                freeTime=vec[i].first;
            }
        }
        
        return ans;
    }
};
