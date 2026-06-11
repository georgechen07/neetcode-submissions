class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> res2;
            for (auto v : res) {
                v.push_back(nums[i]);
                res2.push_back(v);
            }
            res.insert(res.end(), res2.begin(), res2.end());
        }

        return res;
    }
};

// in put size = 0, 1, 2, 3
// output size = 1, 2, 4, 8

// output size = 2 ^ input
// new outputs = previous outputs (excluding newest input) + new outputs (prev + new input)
