class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel=0;
        int start=0;
        int currentFuel=0;
        for(int i=0; i<gas.size(); i++){
            int netfuel=gas[i]-cost[i];
            totalFuel+=netfuel;
            currentFuel+=netfuel;
            if(currentFuel<0){
                start=i+1;
                currentFuel=0;
            }
        }
        return totalFuel>=0?start:-1;
    }
};