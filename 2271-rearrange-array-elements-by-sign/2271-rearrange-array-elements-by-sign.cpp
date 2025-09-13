class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>Positive;
        vector<int>Negative;
        vector<int>Ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                Positive.push_back(nums[i]);
            }
            if(nums[i]<0){
                Negative.push_back(nums[i]);
            }
        }
        bool pos=1;
        int i=0; 
        int j=0;
        while(i<Positive.size() and j<Negative.size()){
            if(pos){
                Ans.push_back(Positive[i]);
                i++;
            }
            else{
                Ans.push_back(Negative[j]);
                j++;
            }
            pos=!pos;
        }
        while(i<Positive.size()){
            Ans.push_back(Positive[i]);
            i++;
        }
        while(j<Negative.size()){
            Ans.push_back(Negative[j]);
            j++;
        }
        return Ans;
    }
};