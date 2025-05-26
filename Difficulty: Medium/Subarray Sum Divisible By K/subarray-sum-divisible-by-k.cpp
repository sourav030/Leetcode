class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
  int subCount(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum = 0;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        sum = ((sum + nums[i]) % k + k) % k;
        if(sum == 0) count++;
        count += mp[sum];
        mp[sum]++;
    }
    return count;
}

};
