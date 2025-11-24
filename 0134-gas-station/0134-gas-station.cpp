class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel=0;
        int currentFuel=0;
        int start=0;
        for(int i=0; i<gas.size(); i++){
            int netFuel=gas[i]-cost[i];
            totalFuel+=netFuel;
            currentFuel+=netFuel;
            if(currentFuel<0){
                currentFuel=0;
                 start=i+1;
            }
        }
        return totalFuel>=0?start:-1;
    }
};