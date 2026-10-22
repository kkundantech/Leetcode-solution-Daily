class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = -1;
        int lo = -1;
        int s = 0;
        int e = nums.size() - 1;

        // first of all we will find the first occurence

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                fo = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // first of all we will find the Last occurence
        s = 0;
        e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                lo = mid;
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return {fo , lo};
    }
};