class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        // Flip the i-th bit: '0' → '1' and '1' → '0'
        result += (nums[i][i] == '0') ? '1' : '0';
    }
    
    return result;
    }
};