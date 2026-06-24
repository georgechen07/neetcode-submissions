class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        auto l = s.begin();
        auto r = s.begin();
        auto test1 = s.begin();
        auto test2 = s.begin();
        int size = 0;
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.contains(*r)) {
                while (m.contains(*r)) {
                    size--;
                    m.erase(*l);
                    l++;
                }
            }
            m.insert({*r, 1});
            size++;
            if (size > maxSize) {
                maxSize = size;
                test1 = l;
                test2 = r;
            }
            r++;
        }

        while (test1 <= test2) {
            cout << *test1;
            test1++;
        }
        cout << '\n';
        return maxSize;
    }
};
