class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // we are using here two pinter approach 
       int j = 0; // it will help to arrange the non dulicate element from the aaray;
       for(int i = 1 ; i < nums.size() ; i++){ // i is iterating and checkinng either it is duplicate or not
            if(nums[i]  != nums[j]){
                j++;
                nums[j] = nums[i];
            }
       }
       return j+1;
    }
};