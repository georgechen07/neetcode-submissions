class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> rec_res;
            recurse(nums, target, i, rec_res, res);
        }

        // AI'D PART

        for (auto& combination : res) {
            std::sort(combination.begin(), combination.end());
        }

        // 2. Sort the outer vector so identical combinations are adjacent to each other
        std::sort(res.begin(), res.end());

        // 3. Use std::unique to push duplicates to the back, then erase them
        res.erase(std::unique(res.begin(), res.end()), res.end());


        return res;
    }

    void recurse(const vector<int>& nums, int target, int start, vector<int> rec_res, vector<vector<int>>& res) {
        int new_target = target - nums[start];
        rec_res.push_back(nums[start]);

        if (new_target == 0) {
            res.push_back(rec_res);
            return;
        } else if (new_target <= 1) {
            return;
        }

        for (int j = start; j < nums.size(); j++) {
            // cout << "start = " << start << " new_target = " << new_target << " and we are trying " << nums[j] << '\n';
            recurse(nums, new_target, j, rec_res, res);
        }
    }
};
