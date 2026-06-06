class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> robbed(100);
        robbed[0] = nums[0];
        robbed[1] = nums[1];
        robbed[2] = max(nums[0] + nums[2], nums[1]);
        for (int i = 3; i < nums.size(); ++i) {
            robbed[i] = max(robbed[i - 2], robbed[i - 3]) + nums[i];
        }

        return max(robbed[nums.size() - 1], robbed[nums.size() - 2]);
    }
};
