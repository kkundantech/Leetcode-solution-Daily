class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        // creation of the pascal's triangle
        vector<vector<int>>ans;
        for(int i = 1 ; i <= n ; i++){
            vector<int>a(i);
            ans.push_back(a);
        }

        // fill the data here 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<=i ;j++){
                if( (j==0) || (i == j)){
                    ans[i][j] = 1;
                }else{
                    ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
                }
            }
        }
        return ans;
    }
};