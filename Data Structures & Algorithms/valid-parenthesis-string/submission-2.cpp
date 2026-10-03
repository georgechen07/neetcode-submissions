class Solution {
public:
    bool checkValidString(string s) {
        if (s[0] == ')') {
            return false;
        }
        auto count = vector<pair<int, int>>(s.size(), pair<int, int>());
        count[0] = {1, 1};
        for (int i = 1; i < s.size(); ++i) {
            count[i] = count[i - 1];
            if (s[i] == '(') {
                ++count[i].first;
                ++count[i].second;
            } else if (s[i] == ')') {
                --count[i].first;
                --count[i].second;
            } else {
                --count[i].first;
                ++count[i].second;
            }
            count[i].first = max(count[i].first, 0);
            if (count[i].second < 0) {
                return false;
            }
        }

        return count.back().first == 0;
    }
};
