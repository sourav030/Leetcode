class Solution {
public:
    int solve(int number){
        int sum=0;
        while(number){
            sum=sum+(number%10);
            number=number/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;

        for(int i=0; i<nums.size(); i++){
            int sum=solve(nums[i]);
            mp[sum].push(nums[i]);
        }
        int ans=-1;

        for(auto ele:mp){
            if(ele.second.size()>=2){
                int first=ele.second.top();
                ele.second.pop();
                int second=ele.second.top();
                ans=max(ans,first+second);
            }
        }
        return ans;
    }
};