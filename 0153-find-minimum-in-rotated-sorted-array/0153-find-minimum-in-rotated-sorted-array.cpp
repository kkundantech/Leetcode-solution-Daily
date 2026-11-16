class Solution {
public:
    int findMin(vector<int>& nums) {
        // brute force approach 
        // int mini = INT_MAX;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(mini > nums[i]){
        //         mini = nums[i];
        //     }
        // }
        // return mini;
        //  now via Binary Search 
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return nums[start];
    }
};