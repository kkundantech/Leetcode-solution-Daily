class Solution {
public:
   int reverse(int x) {
    if(x < INT_MIN){
        return 0;
    }

    int res = 0;
    while(x != 0){
        int ld = x % 10;

        // overflow check
        if(res > INT_MAX/10 || res < INT_MIN/10){
            return 0;
        }

        res = res * 10 + ld;
        x = x / 10;
    }
    return res;
  }
};