class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> d; // to store indices of elements in current window
    vector<int> ans; // result to store maximums
    
    int n = nums.size();
    
    // Process the first k elements (the first window)
    for (int i = 0; i < k; i++) {
        while (!d.empty() && nums[i] >= nums[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    
    // Process the rest of the elements
    for (int i = k; i < n; i++) {
        ans.push_back(nums[d.front()]); // the front of deque is the maximum for the current window

        // Remove elements not part of the window
        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }

        // Remove smaller elements in deque
        while (!d.empty() && nums[i] >= nums[d.back()]) {
            d.pop_back();
        }
        
        // Add current element at the back of the deque
        d.push_back(i);
    }

    // Add the max for the last window
    ans.push_back(nums[d.front()]);
    
    return ans;
}

};