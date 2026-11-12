class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_index = -1;
        int last_index = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                first_index = mid;
                end = mid-1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        start = 0;
        end = nums.size()-1;

         while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                last_index = mid;
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return {first_index , last_index};

    }
};