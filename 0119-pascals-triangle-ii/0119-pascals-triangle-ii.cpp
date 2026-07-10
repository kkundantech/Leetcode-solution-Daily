class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<vector<int>>ans;
        for(int i = 1; i <= n ;i++){
            vector<int>a(i);
            ans.push_back(a);
        }

        // fill the val in the pascal

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }else{
                    ans[i][j] = ans[i-1][j]+ans[i-1][j-1]; //  this condition is most and make sure u understand it
                }
            }
        }
        return ans[rowIndex]; //  last row of the matrix
        
    }
};