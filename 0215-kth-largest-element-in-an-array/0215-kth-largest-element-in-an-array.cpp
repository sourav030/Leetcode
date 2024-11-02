class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // create a priority queue
            priority_queue<int, vector<int>,greater<int>>p;
            for(int i=0;i<k; i++)
            {
                    p.push(nums[i]);
            }
            // compare the nums element with min element of p
            for(int i=k; i<nums.size(); i++)
            {
                    if(nums[i]>p.top())
                    {
                            p.pop();
                            p.push(nums[i]);
                    }
            }
            return p.top();
    }
};