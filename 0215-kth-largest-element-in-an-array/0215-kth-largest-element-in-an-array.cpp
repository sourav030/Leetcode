class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k){
            return -1;
        }
        priority_queue<int, vector<int>, greater<int> >pq;
        int i=0;
        while(i<k){
            pq.push(nums[i]);
            i++;
        }
        while(i<nums.size()){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
        
    }
};