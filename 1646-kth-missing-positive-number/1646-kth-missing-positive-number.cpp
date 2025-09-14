class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto ele:arr){
            mp[ele]=1;
        }
        int val=1;
        int count=0;
        while(count<k){
            if(mp.find(val)==mp.end()){
                count++;
            }
            val++;
        }
        return val-1;
    }
};