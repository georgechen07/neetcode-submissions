class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        auto s1Count = vector<int>(26, 0);
        auto subCount = vector<int>(26, 0);

        for (auto const character : s1) {
            s1Count[character - 'a']++;
        }
        auto l = s2.begin();
        auto r = s2.begin();
        while (r - l < s1.size()) {
            subCount[*r - 'a']++;
            r++;
        }
        if (subCount == s1Count) {
            return true;
        }

        while (r < s2.end()) {
            subCount[*l - 'a']--;
            l++;
            subCount[*r - 'a']++;
            r++;
            if (subCount == s1Count) {
                return true;
            }
        }

        return false;
    }
};
