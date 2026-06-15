class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recurse(0, nums, res);

        return res;
    }

    void recurse(int start, vector<int>& nums, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            recurse(start + 1, nums, res);
            swap(nums[i], nums[start]);
        }
    }
};
