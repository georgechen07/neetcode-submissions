class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        auto res = vector<int>(2 * n);
        for (int i = 0; i < n; ++i) {
            res[i] = nums[i];
            res[n + i] = nums[i];
        }

        return res;
    }
};