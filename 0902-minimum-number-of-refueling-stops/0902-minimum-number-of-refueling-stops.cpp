class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>maxHeap;
        int fuel=startFuel;
        int stop=0;
        int i=0, n=stations.size();

        while(fuel<target){

            while(i<n and stations[i][0]<=fuel){
                maxHeap.push(stations[i][1]);
                i++;
            }
            if(maxHeap.empty()) return -1;

            fuel+=maxHeap.top();
            maxHeap.pop();
            stop++;
        }
    return stop;
    }
};