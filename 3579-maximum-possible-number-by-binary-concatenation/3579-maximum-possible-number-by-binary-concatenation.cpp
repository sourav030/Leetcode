
class Solution {
public:
    int maxGoodNumber(std::vector<int>& nums) {
        int maxNumber = 0;
        
        // Create all permutations of the input array
        std::sort(nums.begin(), nums.end());
        
        do {
            // Concatenate the binary representations of the numbers in this permutation
            std::string concatenatedBinary = "";
            for (int num : nums) {
                concatenatedBinary += std::bitset<8>(num).to_string().substr(std::bitset<8>(num).to_string().find('1'));  // Strip leading zeros
            }
            
            // Convert the concatenated binary string to a decimal number
            int currentNumber = std::stoi(concatenatedBinary, 0, 2);
            
            // Update the maximum number found so far
            maxNumber = std::max(maxNumber, currentNumber);
            
        } while (std::next_permutation(nums.begin(), nums.end()));  // Generate all permutations
        
        return maxNumber;
    }
};
