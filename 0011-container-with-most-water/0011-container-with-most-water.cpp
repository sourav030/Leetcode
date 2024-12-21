class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxWater=-1;
        while(left<right){
          int  width=right-left;
           int  heigh=min(height[left],height[right]);
           int currentStorage=width*heigh;
            maxWater=max(maxWater,currentStorage);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};