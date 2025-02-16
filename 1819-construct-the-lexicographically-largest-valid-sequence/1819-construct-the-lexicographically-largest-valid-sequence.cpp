class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size, 0);
        vector<bool> used(n + 1, false);
        
        function<bool(int)> backtrack = [&](int idx) {
            if (idx == size) return true;
            if (result[idx] != 0) return backtrack(idx + 1);
            
            for (int num = n; num >= 1; --num) {
                if (used[num]) continue;
                
                int secondIdx = (num == 1) ? idx : idx + num;
                if (secondIdx < size && result[secondIdx] == 0) {
                    result[idx] = num;
                    result[secondIdx] = num;
                    used[num] = true;
                    
                    if (backtrack(idx + 1)) return true;
                    
                    result[idx] = 0;
                    result[secondIdx] = 0;
                    used[num] = false;
                }
            }
            return false;
        };
        
        backtrack(0);
        return result;
    }
};
