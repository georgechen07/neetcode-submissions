class Solution {
public:
    string minWindow(string s, string t) {
        auto l = s.begin();
        auto r = s.begin();
        unordered_map<char, int> keyT;
        for (auto const& c : t) {
            keyT[c]++;
        }

        unordered_map<char, int> keyS;
        while (r - l < t.size()) {
            keyS[*r]++;
            r++;
        }

        string_view res = "";
        while (l < s.end()) {
            if (helper(keyS, keyT)) {
                if (r - l < res.size() || res == "") {
                    res = string_view(l, r);
                }
                keyS[*l]--;
                l++;
            } else if (r < s.end()) {
                keyS[*r]++;
                r++;
            } else {
                keyS[*l]--;
                l++;
            }
        }

        return static_cast<string>(res);
    }

    bool helper(unordered_map<char, int> keyS, unordered_map<char, int> keyT) {
        for (const auto [key, element] : keyT) {
            if (element > keyS[key]) {
                return false;
            }
        }

        return true;
    }
};
