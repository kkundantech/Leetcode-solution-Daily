class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // brute force   O{N2
        int n = nums.size();
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         if(nums[i] == nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return 0;

        // sort + find   O{nlogn}

        // sort(nums.begin() , nums.end());
        // for(int i = 0 ; i < n ;i++){
        //     if(i > 0 && nums[i] == nums[i-1]){
        //         return nums[i];
        //     }
        // }
        // return 0;

        // using map O{n}

        unordered_map<int, int>mp;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(nums[i]) != mp.end()){
                return nums[i];
            }
            mp[nums[i]]++;
        }
        return 0;

    }
};