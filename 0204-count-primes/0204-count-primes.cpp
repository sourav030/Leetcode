class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        for (long long i = 2; i * i < n; i++) {
            if (primes[i]) {
                for (long long j = i * i; j < n; j += i)
                    primes[j] = false;
            }
        }
        return count(primes.begin(), primes.end(), true);
    }
};