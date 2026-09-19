class Solution {
public:
    bool backspaceCompare(string s, string t) {
    int ssize = s.length();
    int tsize = t.length();

    int i = ssize - 1;
    int j = tsize - 1;

    int sskip = 0;
    int tskip = 0;

    while(i >= 0 || j >= 0) {

        // For s
        while(i >= 0) {
            if(s[i] == '#') {
                sskip++;
                i--;
            }
            else if(sskip > 0) {
                sskip--;
                i--;
            }
            else {
                break;
            }
        }

        // For t
        while(j >= 0) {
            if(t[j] == '#') {
                tskip++;
                j--;
            }
            else if(tskip > 0) {   // ✅ FIX
                tskip--;
                j--;
            }
            else {
                break;
            }
        }

        char first = i < 0 ? '$' : s[i];
        char second = j < 0 ? '$' : t[j];

        if(first != second) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}
};