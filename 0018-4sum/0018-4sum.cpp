class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>out;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int k=j+1;
                int l=nums.size()-1;
                while(k<l)
                {
                        // long long ans=nums[i]+nums[j]+nums[k]+nums[l];
                    // if(nums[i]+nums[j]+nums[k]+nums[l]<target)
                    // {
                    //     k++;
                    // }
                    //  if(nums[i]+nums[j]+nums[k]+nums[l]>target)
                    // {
                    //     l--;
                    // }
                    long long ta=target;
                    long long ans=ta-nums[i]-nums[j]-nums[k]-nums[l];
                    if(ans>0){
                        k++;
                    }
                    else if(ans<0){
                        l--;
                    }
                    else
                    {
                       out.insert({nums[i], nums[j], nums[k],nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        for(auto tri:out)
        {
            ans.push_back(tri);
        }
        return ans;
    }
};