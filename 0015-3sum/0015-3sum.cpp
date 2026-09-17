class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>>ans; //it will store the Answer
        // sort(nums.begin() , nums.end()); // Sort the Original Array but why ? because it help the pointer to move 
        // int n = nums.size();
        // for(int i  = 0 ; i < n ; i++){ // take one val form here
        //     if(i>0 && nums[i] == nums[i-1]){  // if same val (i > 0 because first val to kabhi duplicate nhi hogi)
        //         continue;
        //     }
        //     int left = i+1;
        //     int right = n-1;
        //     while(left < right){
        //         int sum = nums[i]+nums[left]+nums[right]; 
        //         if(sum == 0){ // match the triplet
        //             ans.push_back({nums[i],nums[left],nums[right]}); // push into the Answer
        //             while(left<right && nums[left] == nums[left+1]){ // indirecly skip the duplicate from the left side 
        //                 left++;
        //             }
        //             while(left < right && nums[right] == nums[right-1]){ // indirecly skip the duplicate from the right side
        //                 right--;
        //             }
        //             left++;
        //             right--;
        //         }else if(sum>0){ // if sum > 0 && nums is already sorted it means that if we will move
        //                         //towards  the lowest val then we will  find the exact sum 
        //             right--;
        //         }else{  // and if sum < 0 so have to go toward highest val so left ++
        //             left++;
        //         }
        //     }
        // }
        // return ans;

        // REVISION SESSION   
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    // skip the duplicate 
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};