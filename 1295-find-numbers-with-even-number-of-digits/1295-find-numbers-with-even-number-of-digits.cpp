class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int number=nums[i];
            string str=to_string(number);
            int size=str.length();
            if(size%2==0){
                ans++;
            }
        }
        return ans;
    }
};