class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // auto vec = vector<int>(n, 0);
        // vec[0] = 1;

        // for (auto const& edge : edges) {
        //     if (edge[0] > edge[1]) {
        //         vec[edge[0]]++;
        //     } else {
        //         vec[edge[1]]++;
        //     }
        // }

        // for (auto const parent : vec) {
        //     // cout << parent << '\n';
        //     if (parent != 1) {
        //         return false;
        //     }
        // }

        // return true;
        
        sort(edges.begin(), edges.end());
        
        vector<set<int>> levels;
        levels.push_back(set<int>{0});
        for (auto const edge : edges) {
            int j = levels.size();
            for (int i = 0; i < j; ++i) {
                if (levels[i].contains(edge[0])) {
                    if (i == j - 1) {
                        levels.push_back(set<int>{edge[1]});
                    } else {
                        levels[i + 1].insert(edge[1]);
                    }
                    break;
                } else if (levels[i].contains(edge[1])) {
                    if (i == j - 1) {
                        levels.push_back(set<int>{edge[0]});
                    } else {
                        levels[i + 1].insert(edge[0]);
                    }
                    break;
                }
            }
        }

        set<int> found;
        for (auto const s : levels) {
            cout << "\nnew lvl\n";
            for (auto const node : s) {
                cout << node << " ";
                if (found.contains(node)) {
                    return false;
                } else {
                    found.insert(node);
                }
            }
        }

        return found.size() == n;
    }
};
