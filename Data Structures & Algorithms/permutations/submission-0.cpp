class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> rec_res;
        recurse(0, nums, rec_res, res);

        return res;
    }

    void recurse(int start, const vector<int>& nums, vector<int>& rec_res, vector<vector<int>>& res) {
        if (rec_res.size() == nums.size()) {
            res.push_back(rec_res);
            return;
        }

        for (int i = 0; i <= rec_res.size(); i++) {
            rec_res.insert(rec_res.begin() + i, nums[start]);
            recurse(start + 1, nums, rec_res, res);
            rec_res.erase(rec_res.begin() + i);
        }
    }
};
