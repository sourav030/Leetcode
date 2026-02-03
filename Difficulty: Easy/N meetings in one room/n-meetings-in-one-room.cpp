class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>arr;
        for(int  i=0; i<start.size(); i++){
            arr.push_back({start[i],end[i]});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int>&a, pair<int,int>&b){
            return a.second<b.second;
        });
        
        int endTime=arr[0].second;
        int count=1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i].first>endTime){
                count++;
                endTime=arr[i].second;
            }
        }
        return count;
    }
};