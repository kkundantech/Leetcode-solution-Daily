class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // brute force approach 
        // int n = nums.size() - 1;
        // while(k--){
        //      int temp = nums[n];
        //     for(int i = nums.size()-2 ; i >= 0 ; i--){
        //         nums[i+1] = nums[i];
        //     }
        //     nums[0] = temp;
        // }
        
    //    // optimal sotition 
    //    int n = nums.size();
    //    k = k % n;
    //    reverse(nums.begin() , nums.end());
    //    reverse(nums.begin(), nums.begin()+k);
    //    reverse(nums.begin()+k , nums.end());
    
    int n = nums.size();
     k = k%n;
    reverse(nums.begin() , nums.end());
    reverse(nums.begin() , nums.begin() + k);
    reverse(nums.begin() + k , nums.end());
    }
};