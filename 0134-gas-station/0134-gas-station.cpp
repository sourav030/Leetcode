class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int current=0;
        int start=0;

        for(int i=0; i<gas.size(); i++){
            int netFuel=gas[i]-cost[i];
            total+=netFuel;
            current+=netFuel;
            if(current<0){
                current=0;
                start=i+1;
            }
        }
        return total>=0?start:-1;
    }
};