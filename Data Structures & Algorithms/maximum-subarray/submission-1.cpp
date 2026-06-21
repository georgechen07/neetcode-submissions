class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (sum > 0 && nums[i] > 0) {
                sum += nums[i];
            } else if (nums[i] > sum) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};
