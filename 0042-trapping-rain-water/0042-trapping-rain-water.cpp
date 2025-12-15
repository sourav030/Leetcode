class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater=0;
        int maxBuilding=0;
        int indexMax=0;
        for(int i=0; i<height.size(); i++){
            if(height[i]>maxBuilding){
                maxBuilding=height[i];
                indexMax=i;
            }
        }
        int prev=height[0];
        for(int i=0; i<indexMax; i++){
            prev=max(prev,height[i]);
            int water=prev-height[i];
            totalWater+=water;
        }
        int j=height.size()-1;
        prev=height[j];
        for(int i=j; i>indexMax; i--){
            prev=max(prev,height[i]);
            int water=prev-height[i];
            totalWater+=water;
        }
        return totalWater;
    }
};