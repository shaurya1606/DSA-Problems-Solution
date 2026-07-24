class Solution {
public:

    bool checkBelonging( string str1, string str2 ) {
        int n1 = str1.size();
        int n2 = str2.size();

        if(n1 > n2) return false;

        int i = 0, j = 0;

        while(i < n1) {
            int flag = 0;
            while (j < n2) {
                if (str1[i] == str2[j]) {
                    flag = 1;
                    j++;
                    break;
                }
                j++;
            }
            if(!flag) return false;
            i++;
        }
        return true;
    }

    bool isSubsequence(string s, string t) {
        string str1 = s;
        string str2 = t;
        bool check = checkBelonging( str1, str2 ) ;
        return check;
    }
};