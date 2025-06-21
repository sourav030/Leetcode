class Solution {
public:
    const int M = 1e9 + 7;

    long long solve(long long a, long long b) {
        if (b == 0) return 1;
        long long half = solve(a, b / 2);
        long long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = solve(5, (n + 1) / 2);
        long long oddPos = solve(4, n / 2);
        return (evenPos * oddPos) % M;
    }
};
