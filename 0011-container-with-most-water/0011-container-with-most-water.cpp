class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int h=min(height[left], height[right]);
            int w=right-left;
            ans=max(ans,h*w);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};