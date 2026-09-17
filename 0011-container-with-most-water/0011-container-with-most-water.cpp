class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       int i = 0;
       int j = n-1;
       int maxArea = 0;
       while(i<j){
        int w = j-i;
        int h  = min(height[i] , height[j]); // jtna height hoga wahi tak pani bharega esiliye dono me se chhoti height lenge
        int area = w*h;
        maxArea = max(maxArea,area);
        if(height[i] > height[j]){ //  hame height se fayada hai to hum jiska jyada hai humuse use rakhe rhenge 
            j--;
        }else{
            i++;
        }

       }
       return maxArea; 
    }
};