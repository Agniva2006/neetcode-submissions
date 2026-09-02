class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>Char;
        int left =0 ;
        int maxlength=0;
        for(int right =0; right<s.length();right++){
            while(Char.count(s[right])){
               Char.erase(s[left]);
               left++;
            }
             Char.insert(s[right]);
             maxlength=max(right-left+1,maxlength);
        }
        return maxlength;
    }
};
