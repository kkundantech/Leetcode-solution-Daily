class Solution {
public:
   int missingNumber(vector<int>& nums) {
    int n = nums.size();

    vector<bool> visited(n + 1, false);

    for (int i = 0; i < n; i++) {
        visited[nums[i]] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (!visited[i]) {
            return i;
        }
    }

    return -1;
}
};