class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int end=0;
        int start=0;
        int count=0;
        while(end<arr.size()){
            sum+=arr[end];
            if(end-start+1>k){
                sum-=arr[start];
                start++;
            }
            if(end-start+1==k){
                int ans=sum/k;
                if(ans>=threshold){
                    count++;
                }
            
            }
            
            end++;
        }
        return count;
    }
};