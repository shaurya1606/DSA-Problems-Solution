class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        reverse(s.begin(), s.end());
        int k = 0;
        while(i < s.length()) {
            while(i < s.length() && !isalnum(s[i])) {
                i++;
            }
            while(i < s.length() && isalnum(s[i])) {
                s[j++] = s[i++];
            }
            reverse(s.begin()+k, s.begin()+j);
            s[j] = ' ';
            j++;
            k = j;
            i++;
            while(i < s.length() && !isalnum(s[i])) {
                i++;
            }
        }
    
        s.resize(j-1);
        return s;
    }
};