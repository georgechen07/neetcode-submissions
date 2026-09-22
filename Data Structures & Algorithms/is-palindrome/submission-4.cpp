class Solution {
public:
    bool isPalindrome(string s) {
        auto start = s.begin();
        auto end = s.end() - 1;
        auto e = end;

        while (start != e) {
            while (!isalnum(*start)) start++;
            while (!isalnum(*end)) end--;
            if (start >= e) break;

            if (tolower(*start) != tolower(*end)) return false;
            start++;
            end--;
        }

        return true;
    }
};
