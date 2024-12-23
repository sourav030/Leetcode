class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     

            int index=-1;
            int n=nums.size();
            // Hume last smallest index find krna hai to last se traverse krenge agar mil gaya to break

            for(int i=n-2; i>=0; i--){
                if(nums[i]<nums[i+1]){
                    index=i;
                    break;
                }
            }
            // agar indx=-1 hai to array descending order main useko reverse krke bejh denge
            if(index==-1){
                reverse(nums.begin(),nums.end());
                return;
            }
            // ab chote element index ko swap krna hai largest ke smallest element se

            for(int i=n-1; i>index; i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }

            reverse(nums.begin()+index+1,nums.end());
    }
};