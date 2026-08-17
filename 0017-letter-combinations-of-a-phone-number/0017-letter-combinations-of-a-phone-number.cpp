class Solution {
public:

    vector<string> ans;

    void pad(string p, string up) {

        // Base case
        if (up.empty()) {
            ans.push_back(p);
            return;
        }

        string mapping[] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        int digit = up[0] - '0';

        string letters = mapping[digit];

        for (char ch : letters) {
            pad(p + ch, up.substr(1));
        }
    }

    vector<string> letterCombinations(string digits) {

        ans.clear();

        if (digits.empty()) {
            return {};
        }

        pad("", digits);

        return ans;
    }
};