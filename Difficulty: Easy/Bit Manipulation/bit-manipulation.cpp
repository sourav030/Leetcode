class Solution {
  public:
    void bitManipulation(int num, int i) {
        int mask = 1 << (i - 1);

        // 1. Get ith bit
        int getBit = (num & mask) ? 1 : 0;

        // 2. Set ith bit
        int setBit = num | mask;

        // 3. Clear ith bit
        int clearBit = num & (~mask);

        cout << getBit << " " << setBit << " " << clearBit;
    }
};
