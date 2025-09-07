class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // build factorial (n-1)! and number list [1..n]
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1; // convert to 0-based index

        while (true) {
            int index = k / fact;
            ans += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            if (numbers.size() == 0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
