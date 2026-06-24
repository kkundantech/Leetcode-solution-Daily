class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0;
        // int j = 0;
        // vector<int>ans(m+n);
        // int k = 0;
        // while(i < m && j < n){
        //     if(nums1[i] <= nums2[j]){
        //         ans[k] = nums1[i];
        //         i++;
        //     }else{
        //         ans[k] = nums2[j];
        //         j++;
        //     }
        //     k++;
        // }

        // // remaining case
        // while(i<m){
        //     ans[k] = nums1[i];
        //     k++;
        //     i++;
        // }

        // while(j<n){
        //     ans[k] = nums2[j];
        //     j++;
        //     k++;
        // }

        // for(int i = 0 ; i < ans.size() ; i++){
        //     nums1[i] = ans[i];
        // }  


    int i = m - 1;      // last valid element of nums1
    int j = n - 1;      // last element of nums2
    int k = m + n - 1;  // last position in nums1

    while(i >= 0 && j >= 0){

        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }

        k--;
    }

    // if nums2 still has elements
    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
     
    }
};