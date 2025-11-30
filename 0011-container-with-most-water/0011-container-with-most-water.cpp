class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxWater=0;
        while(i<=j)
        {
            int w=abs(i-j);
            int h=min(height[i], height[j]);
            maxWater=max(maxWater,w*h);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxWater;
    }
};