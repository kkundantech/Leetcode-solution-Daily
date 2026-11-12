class Solution {
public:
    int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            
            if(s == e){
                return s;
             }

             int mid = s + (e - s) / 2;
                // case 1;
                if((mid - 1 >= s) && (nums[mid-1] > nums[mid])){
                    return mid-1;
                }
                
                // case 2;
                if((mid+1 <= e) && (nums[mid + 1] < nums[mid])){
                    return mid;
                }

                // now we will itrate the on the Array 

                if(nums[s] > nums[mid]){
                    e = mid -1;
                }else{
                    s = mid + 1;
                }
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
        
        // brute force
        // for(int i = 0 ; i < nums.size() ;i++){
        //     if(nums[i] == target){
        //         return i;
        //         break;
        //     }
        // }
        // return -1;
    }
};