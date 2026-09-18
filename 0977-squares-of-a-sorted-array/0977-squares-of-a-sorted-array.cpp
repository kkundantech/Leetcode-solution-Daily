class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // just basic approach like brute force 
        // for(int i = 0 ; i < nums.size() ; i++){
        //     nums[i] = nums[i]*nums[i];
        // }
        // sort(nums.begin() , nums.end());
        // return nums;

        // Now we will solve using two pointer
        //  vector<int>ans(nums.size());
        // int left = 0;
        // int right = nums.size()-1;
        // int k = nums.size() - 1;
        // while(left<=right){
        //     int s1 = nums[left] * nums[left];
        //     int s2 = nums[right] * nums[right];
        //     if(s1 > s2){
        //         ans[k] = s1;
        //         left++;
        //     }else{
        //         ans[k] = s2;
        //         right--;  
        //     }
        //     k--;
        // }
        // return ans;

        // Revesion time


        vector<int>ans(nums.size());
        int left = 0;
        int right = nums.size()-1;
        int k = nums.size()-1;
        while(left<=right){
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if(leftSquare > rightSquare){
                ans[k] = leftSquare;
                left++;
            }else{
                ans[k] = rightSquare;
                right--;
            }
            k--;
        }
        return ans;
    }
};