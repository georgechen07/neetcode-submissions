class Solution {
public:
    bool isPalindrome(string s) {
        auto start = s.begin();
        auto end = s.end();
        end--;
        while (end > start) {
            while (!isalnum(*start) && end > start) {
                cout << *start << '\n';
                start++;
            }
            while (!isalnum(*end) && end > start) {
                cout << *end << '\n';
                end--;
            }
            if (toupper(*end) != toupper(*start)) {
                return false;
            }
            end--;
            start++;
        }

        return true;
    }
};
