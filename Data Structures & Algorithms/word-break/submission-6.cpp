class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> lexicon;
        for (auto const& word : wordDict) {
            lexicon.insert(word);
        }
        
        vector<int> dp(s.size(), 0);
        recurse(0, s, lexicon, dp);

        if (dp[0] == 1) {
            return true;
        } else {
            return false;
        }
    }

    int recurse(int start, string& s, unordered_set<string>& lexicon, vector<int>& dp) {
        if (start == s.size() || dp[start] == 1 || dp[0] == 1) {
            return 1;
        } else if (dp[start] == 2) {
            return 2;
        }

        string curr;
        for (int i = start; i < s.size(); i++) {
            curr += s[i];
            if (lexicon.contains(curr)) {
                dp[start] = recurse(i + 1, s, lexicon, dp);
                if (dp[start] == 1) {
                    return 1;
                }
            }
        }

        return 2;
    }
};