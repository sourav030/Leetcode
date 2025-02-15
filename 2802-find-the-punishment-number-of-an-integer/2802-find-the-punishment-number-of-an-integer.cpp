class Solution {
public:
    bool canPartition(string s, int target, int index, int sum) {
        if (index == s.size()) {
            return sum == target;
        }
        
        int num = 0;
        for (int j = index; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0'); // Form the number from substring
            if (num + sum > target) break; // No need to continue if sum exceeds target
            if (canPartition(s, target, j + 1, sum + num)) {
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int totalSum = 0;
        
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            
            if (canPartition(squareStr, i, 0, 0)) {
                totalSum += square;
            }
        }
        
        return totalSum;
    }
};
