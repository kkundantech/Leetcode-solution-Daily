class Solution {
public:
    bool isPalindrome(string s) {
     int i = 0;
     int j = s.size()-1;
     while(i<j){
        if(!isalnum(s[i])){ // check whether it is character or not.
            i++;
        }else if(!isalnum(s[j])){
            j--;
        }else{
            if(toupper(s[i]) != toupper(s[j])){
                return false;
            }

            i++;
            j--;
        }       
    }
     return true;   
    }
};