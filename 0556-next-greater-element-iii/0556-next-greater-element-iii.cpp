class Solution {
public:
    int nextGreaterElement(int n) {
        string ans = to_string(n);
        int index = -1;
        for (int i = ans.length() - 1; i > 0; i--) {
            if (ans[i] > ans[i - 1]) {
                index = i - 1;
                break;
            }
        }

        if (index == -1) {
            return -1;
        }

        for (int i = ans.length() - 1; i > index; i--) {
            if (ans[i] > ans[index]) {
                swap(ans[i], ans[index]);
                break;
            }
        }

        cout << ans << endl;
        reverse(ans.begin() + index + 1, ans.end());
        cout << ans << endl;

        long long res = stoll(ans);
        if (res > INT_MAX) {
            return -1;
        }
        return (int)res;
    }
};