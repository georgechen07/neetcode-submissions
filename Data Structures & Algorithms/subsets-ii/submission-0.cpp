class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});

        auto last_used = vector<int>(41, 0);

        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> res2;
            int start = last_used[nums[i] + 20];
            for (int j = last_used[nums[i] + 20]; j < res.size(); ++j) {
                auto temp = res[j];
                temp.push_back(nums[i]);
                res2.push_back(temp);
            }
            last_used[nums[i] + 20] = res.size();
            res.insert(res.end(), res2.begin(), res2.end());
        }

        return res;
    }
};
