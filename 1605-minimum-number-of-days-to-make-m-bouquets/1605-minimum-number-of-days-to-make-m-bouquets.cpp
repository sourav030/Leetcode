class Solution {
public:
    bool isValid(vector<int>&bloomDay,int m, int k, int val){
        int count=0;
        int bouket=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=val){
                count++;
            }
            else{
                count=0;
            }
            if(count==k){
                bouket++;
                count=0;
            }
            if(bouket==m){
                return true;
            }
        }
        return bouket==m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        // long long a=m*k;
        // if(a>bloomDay.size()) return -1;
        int low=1;
        int high=1;
        for(int i=0; i<bloomDay.size(); i++){
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};