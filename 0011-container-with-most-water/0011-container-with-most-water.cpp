class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int width=j-i;
            int area=min(height[i], height[j])*width;
            maxArea=max(maxArea,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};