class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int idx=-1;
        if(arr.size()<3){
            return false;
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                idx=i;
            }
        }
      
        if(arr[arr.size()-1]==maxi or maxi==arr[0]){
            return false;
        }      

        int lmaxi=maxi;
        int lidx=idx-1;
        while(lidx>=0){
            if(arr[lidx]<lmaxi){
                lmaxi=arr[lidx];
            }
            else{
                
                return false;
            }
            lidx--;
        }
        idx++;
        while(idx<arr.size()){
            if(arr[idx]<maxi){
                maxi=arr[idx];
            }
            else{
                cout<<maxi<<" "<<arr[idx];
                return false;
            }
            idx++;
        }
        return true;
    }
};