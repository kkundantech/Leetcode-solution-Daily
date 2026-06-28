class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxEnding = 0;
        int maxSum = 0;

        int minEnding = 0;
        int minSum = 0;

        for (int x : nums) {

            // Maximum subarray
            maxEnding = max(x, maxEnding + x);
            maxSum = max(maxSum, maxEnding);

            // Minimum subarray
            minEnding = min(x, minEnding + x);
            minSum = min(minSum, minEnding);
        }

        return max(maxSum, abs(minSum));
    }
};