class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];
    }

    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();

        for (int currSize = 1; currSize < n; currSize *= 2)
        {
            for (int left = 0; left < n - 1; left += 2 * currSize)
            {
                int mid = min(left + currSize - 1, n - 1);
                int right = min(left + 2 * currSize - 1, n - 1);

                if (mid < right)
                    merge(nums, left, mid, right);
            }
        }

        return nums;
    }
};