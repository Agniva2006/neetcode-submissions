class Solution {
public:
    bool isPalindrome(string s) {
        string Newstr = "";
        for (char c : s){
            if(isalnum(c)){
                Newstr += tolower(c);
            }
        }
        return Newstr == string(Newstr.rbegin(),Newstr.rend());
    }
};