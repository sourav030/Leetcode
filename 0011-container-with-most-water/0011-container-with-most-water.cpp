class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; 
        int j=height.size()-1;
        int water=0;
        while(i<j){
            int width=j-i;
            int heigh=min(height[i],height[j]);
            water=max(water,width*heigh);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return water;
    }
};