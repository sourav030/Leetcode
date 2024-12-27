class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;   // Total net gas for the circuit
        int current_tank = 0; // Net gas for the current segment
        int start_station = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            current_tank += gas[i] - cost[i];

            // If the tank becomes negative, reset the starting station
            if (current_tank < 0) {
                start_station = i + 1; // Move to the next station
                current_tank = 0;     // Reset the current tank
            }
        }

        // If total_tank is negative, no solution exists
        return total_tank >= 0 ? start_station : -1;
    }
};
