class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }

      
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for(auto &car : cars){
            double t = car.second;
            if(t > lastTime){
                fleets++;
                lastTime = t;
            }
          
        }

        return fleets;
    }
};
