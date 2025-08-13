class Solution {
public:
    #define P pair<int,int>
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<P,vector<P>, greater<P> >pq;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                pq.push({nums[i],i});
            }
        }

        while(k>0 and !pq.empty()){
            int idex=pq.top().second;
            pq.pop();
            nums[idex]=-nums[idex];
            k--;
        }
        sort(nums.begin(),nums.end());
        int sum=0;
        int idx=0;
        while(k>0){
            nums[idx]=-nums[idx];
            k--;
        }
        for(auto ele:nums){
            cout<<ele<<" ";
            sum+=ele;
        }
        return sum;
        
    }
};