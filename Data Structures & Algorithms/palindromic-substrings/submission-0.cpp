class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;;
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            int even = 0;
            int odd = 0;

            while (i - j >= 0 && i + j < s.length()) {
                if ((j == 0 or even == 1) and (i + j + 1 < s.length() and s[i - j] == s[i + j + 1])) {
                    res++;
                    even = 1;
                } else {
                    even = 0;
                }
                if ((j == 0 or odd == 1) and s[i - j] == s[i + j]) {
                    res++;
                    odd = 1;
                } else {
                    odd = 0;
                }

                if (even == 0 && odd == 0) {
                    break;
                } else {
                    j++;
                    continue;
                }
            }
        }

        return res;
    }
};
