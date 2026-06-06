class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            int even = 0;
            int odd = 0;

            while (i - j >= 0 && i + j < s.length()) {
                if ((j == 0 or even == 1) and (i + j + 1 < s.length() and s[i - j] == s[i + j + 1])) {
                    // cout << i << " " << j << " " << s[i - j] << s[i + j + 1] << '\n';
                    if (2 * j + 2 > res.length()) {
                        res = s.substr(i - j, 2 * j + 2);
                        // cout << res << '\n';
                    }
                    even = 1;
                } else {
                    even = 0;
                }
                if ((j == 0 or odd == 1) and s[i - j] == s[i + j]) {
                    if (2 * j + 1 > res.length()) {
                        res = s.substr(i - j, 2 * j + 1);
                    }
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
