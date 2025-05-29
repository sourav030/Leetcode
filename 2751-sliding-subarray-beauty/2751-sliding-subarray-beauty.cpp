class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
          vector<int> answer;
        vector<int> count(101,0);
        // -50 -> 0 index ans so on...

        for(int i=0; i<k; i++) {
            count[nums[i] + 50]++;
        }

        for(int i=k; i<=nums.size(); i++) {
            int negativeSeen = 0;
            int beauty = 0;

            for(int j=0; j<50; j++) {
                negativeSeen += count[j];
                if(negativeSeen >= x) {
                    beauty = j - 50;
                    break;
                }
            }

            answer.push_back(negativeSeen >= x ? beauty : 0);

            // REMOVE STARTING AND ADD CURRENT
            if(i < nums.size()) {
                count[nums[i] + 50]++;
                count[nums[i-k] + 50]--;
            }
        }
        return answer;
    }
};