class Solution {
public:
    // Add two numeric strings and return the result string
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // Recursive check using string addition
    bool check(string &s, int start, string num1, string num2) {
        string sum_str = addStrings(num1, num2);

        // If next part of s doesn't match the sum, return false
        if (s.substr(start, sum_str.size()) != sum_str)
            return false;

        // If we've reached the end of string successfully
        if (start + sum_str.size() == s.length())
            return true;

        return check(s, start + sum_str.size(), num2, sum_str);
    }

    bool isSumString(string &s) {
        int n = s.length();

        for (int i = 1; i < n; i++) {
            string num1 = s.substr(0, i);

            // Leading zero check
            if (num1.length() > 1 && num1[0] == '0') continue;

            for (int j = 1; i + j < n; j++) {
                string num2 = s.substr(i, j);

                if (num2.length() > 1 && num2[0] == '0') continue;

                if (check(s, i + j, num1, num2))
                    return true;
            }
        }
        return false;
    }
};
