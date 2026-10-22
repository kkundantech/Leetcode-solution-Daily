class Solution {
public:
    int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int m = s + (e - s) / 2;

        while (s <= e) {
            if (s == e) {
                return s;
            }

            // Case 1: Previous element is greater
            if (m - 1 >= s && nums[m - 1] > nums[m]) {
                return m - 1;
            }

            // Case 2: Current element is greater than next
            if (m + 1 <= e && nums[m] > nums[m + 1]) {
                return m;
            }

            // Case 3: Pivot lies on the left
            if (nums[s] > nums[m]) {
                e = m - 1;
            } 
            // Case 4: Pivot lies on the right
            else {
                s = m + 1;
            }

            m = s + (e - s) / 2;
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] > target) {
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);

        // Search in the first sorted part
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, 0, pivotIndex, target);
        } 
        // Search in the second sorted part
        else {
            return binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }
    }
};