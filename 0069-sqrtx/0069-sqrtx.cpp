class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;

        int start = 1, end = x;
        int ans = 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            long long val = (long long)mid * mid;   

            if (val == x)
                return mid;

            else if (val < x) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
