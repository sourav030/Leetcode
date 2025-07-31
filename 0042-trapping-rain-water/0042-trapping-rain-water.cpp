class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int maxi = 0;
        int idx = 0;

      
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxi) {
                maxi = height[i];
                idx = i;
            }
        }

        int totalWater = 0;

      
        int leftMax = height[0];
        for (int i = 1; i < idx; i++) {
            leftMax = max(leftMax, height[i]);
            totalWater += leftMax - height[i];
        }

      
        int rightMax = height[height.size() - 1];
        for (int i = height.size() - 2; i > idx; i--) {
            rightMax = max(rightMax, height[i]);
            totalWater += rightMax - height[i];
        }

        return totalWater;
    }
};
