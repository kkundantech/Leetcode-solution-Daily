class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int n1 = x;
        long long rev = 0;
        while(x != 0){
            int ld = x % 10;
            rev = (10 * rev) + ld;
            x /= 10;
        }
        return rev == n1;
    }
};