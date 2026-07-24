class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto& ch: s) {
            if(isalnum(ch)) {
                str += tolower(ch);
            }
        }
        
        for(int i = 0; i < str.length(); i++) {
            if(!(str[i] == str[str.length()-1-i])) {
                return false;
            }
        }

        return true;
    }
};