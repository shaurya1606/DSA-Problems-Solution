class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int i = 0;
        int j = 1;
        int n = s.length();
        int ans = 0;

        if(n == 1) {
            return mp[s[i]];
        }

        while(i < n) {
            if(mp[s[i]] < mp[s[j]]) {
                ans += mp[s[j]] - mp[s[i]];
                i++;
                j++;
            } else  {
                ans += mp[s[i]];
            }
            i++;
            j++;
        }
        return ans;
    }
};