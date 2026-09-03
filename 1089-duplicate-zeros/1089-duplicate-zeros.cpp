class Solution {
public:
    void shift(vector<int>&arr, int idx){
        int n=arr.size()-2;
        while(n>=idx){
            arr[n+1]=arr[n];
            n--;
        }
    }
    void duplicateZeros(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                shift(arr,i+1);
                if(i+1<arr.size()){
                    arr[i+1]=0;
                }
                i++;
            }
        }
    }
};