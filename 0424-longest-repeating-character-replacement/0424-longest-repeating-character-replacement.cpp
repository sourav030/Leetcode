class Solution {
public:
    int characterReplacement(string s, int k) {
         unordered_map<char, int> freq;
    int left = 0, maxFreq = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;
        maxFreq = max(maxFreq, freq[s[right]]);
        
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left]]--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
    }
};