
class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) return 1.0;

        double half = solve(x, n / 2);
        double result = half * half;

        if (n % 2 != 0) {
            result *= x;
        }

        return result;
    }

    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            return 1.0 / solve(x, -power);
        }

        return solve(x, power);
    }
};
