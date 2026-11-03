
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int s = 1;
       int e = *max_element(piles.begin() , piles.end());
       int ans = 0;
       while(s <= e){
        int mid = s + (e - s)/2; // amount of banana consume in one hour
        long long total_time = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            total_time = total_time + piles[i]/mid;
            if(piles[i] % mid){
                total_time++; // if any val is availalbe like in decimal it will count it
            }
        }

        if(total_time > h){
            s = mid + 1;
        }else{
            ans = mid ;
            e = mid -1;
        }

       }
       return ans;
    }
};
