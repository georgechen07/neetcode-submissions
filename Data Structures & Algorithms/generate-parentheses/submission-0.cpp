class Solution {
public:
    vector<string> generateParenthesis(int n) {
        list<pair<string, int>> res;
        if (n == 0) {
            return vector<string>();
        }
        res.push_back({"", 0});

        for (int i = 0; i < 2 * n; ++i) {
            cout << "PRECOPY\n";
            for (auto const& sol : res) {
                cout << sol.first << ", ";
            }
            cout << "\n";
            // duplicate all valid solutions
            auto size = res.end();
            for (auto j = res.begin(); j != size; ++j) {
                if (j->second > j->first.size() / 2 && j->second < n) {
                    res.insert(j, *j);
                }
            }
            cout << "POSTCOPY\n";
            for (auto const& sol : res) {
                cout << sol.first << ", ";
            }
            cout << "\n";

        // (()), ()()
        // llrr, lrlr

        // "((()))","(()())","(())()","()(())","()()()"
        // lllrrr llrlrr llrrlr lrllrr lrlrlr
        // l
        // lr, ll
        // lr, ll, ll
        // lrl, llr, lll
            if (res.front().first == "") {
                res.front().first += "(";
                ++res.front().second;
                continue;
            }
            auto og_end = res.end();
            string og_prev = "a";
            for (auto j = res.begin(); j != og_end; ++j) {
                // cout << "j = " << j << " size = " << res.size() << '\n';
                if (og_prev == j->first || j->second >= n) {
                    og_prev = j->first;
                    j->first += ")";
                } else {
                    og_prev = j->first;
                    j->first += "(";
                    ++j->second;
                }
            }
        }

        vector<string> returned;
        for (auto const& sol : res) {
            returned.push_back(sol.first);
        }
        return returned;
    }
};
