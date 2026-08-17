class Solution {
public:
    int characterReplacement(string s, int k) {
        auto l = s.begin();
        auto r = s.begin();

        auto m = vector<int>(26);
        int max_freq = 0;
        int max_len = 0;

        while (r < s.end()) {
            ++m[*r - 'A'];
            max_freq = max(max_freq, m[*r - 'A']);
            ++r;

            if (r - l - max_freq > k) {
                --m[*l - 'A'];
                ++l;
            }

            max_len = max(max_len, static_cast<int>(r - l));
        }

        return max_len;
    }
};
