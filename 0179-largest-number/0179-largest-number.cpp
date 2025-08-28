class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for(int num : nums) strNums.push_back(to_string(num));

        // Custom sort: jo combination bada number de, wo pehle aayega
        sort(strNums.begin(), strNums.end(), [](string &a, string &b){
            return a + b > b + a;
        });

        // Edge case: agar sab 0 hain
        if(strNums[0] == "0") return "0";

        string ans = "";
        for(auto &s : strNums) ans += s;
        return ans;
    }
};
