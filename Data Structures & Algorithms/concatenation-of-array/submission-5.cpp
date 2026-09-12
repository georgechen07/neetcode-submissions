class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto res = vector<int>(2 * nums.size());
        res.reserve(2 * nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = nums[i];
            res[nums.size() + i] = nums[i];
        }

        return res;
    }
};