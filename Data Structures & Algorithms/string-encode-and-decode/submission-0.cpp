class Solution {
public:

    string encode(vector<string>& strs) {
        auto res = string();
        for (auto const& word : strs) {
            res += word;
            res += '\n';
        }

        return res;
    }

    vector<string> decode(string s) {
        auto res = vector<string>();
        auto word = string();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\n') {
                res.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }

        return res;
    }
};
