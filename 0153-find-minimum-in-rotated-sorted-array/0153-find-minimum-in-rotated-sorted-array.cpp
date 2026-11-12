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
        int s = 0;
        int e = nums.size()-1;
        while(s<e){
            int mid = s + (e -s)/2;
            if(nums[mid] > nums[e]){
                s = mid + 1;
            }else{
                e = mid;
            }
        }
        return nums[s];
    }
};