class Solution {
public:
    string addBinary(string arr, string brr) {
        string ans = "";
        int carry = 0;

        int i = arr.length() - 1;
        int j = brr.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += arr[i--] - '0';

            if (j >= 0)
                sum += brr[j--] - '0';

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};