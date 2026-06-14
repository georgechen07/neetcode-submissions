class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};

        sort(candidates.begin(), candidates.end());

        vector<int> rec_res = {};
        recurse(candidates, target, 0, rec_res, res);

        return res;
    }

    void recurse(const vector<int>& nums, int target, int start, vector<int> rec_res, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(rec_res);
            return;
        } else if (target <= 0 || start >= nums.size()) {
            return;
        }

        /*
        for (int j = start; j < nums.size(); j++) {
            // cout << "start = " << start << " new_target = " << new_target << " and we are trying " << nums[j] << '\n';
            recurse(nums, new_target, j, rec_res, res);
        }
        */

        rec_res.push_back(nums[start]);
        recurse(nums, target - nums[start], start + 1, rec_res, res);
        rec_res.pop_back();

        int i = 1;
        while (start + i < nums.size() && nums[start + i] == nums[start]) {
            i++;
        }
        recurse(nums, target, start + i, rec_res, res);
    }
};
