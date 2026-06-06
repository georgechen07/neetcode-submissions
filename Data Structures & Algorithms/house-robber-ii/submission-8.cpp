class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        } else if (nums.size() == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }

        vector<int> robbed(100);
        vector<int> used(100);

        robbed[0] = nums[0];
        used[0] = 1;
        robbed[1] = max(nums[0], nums[1]);
        if (nums[0] <= nums[1]) {
            used[1] = 0;
        } else {
            used[1] = 1;
        }

        robbed[2] = max(robbed[1], robbed[0] + nums[2]);
        used[2] = 1;
        if (robbed[2] == robbed[1] && used[1] == 0) {
            used[2] = 0;
        }
        if (robbed[2] == robbed[0] + nums[2] && used[0] == 0) {
            used[2] = 0;
        }

        for (int i = 3; i < nums.size() - 1; ++i) {
            robbed[i] = max(max(robbed[i - 1], robbed[i - 2] + nums[i]), robbed[i - 3] + nums[i]);
            used[i] = 1;
            if (robbed[i] == robbed[i - 1] && used[i - 1] == 0) {
                used[i] = 0;
            }
            if (robbed[i] == robbed[i - 2] + nums[i] && used[i - 2] == 0) {
                used[i] = 0;
            }
            if (robbed[i] == robbed[i - 3] + nums[i] && used[i - 3] == 0) {
                used[i] = 0;
            }

            cout << i << " " << used[i] << endl;
            cout << robbed[i] << '\n';
        }

        robbed[nums.size() - 1] = max(max(robbed[nums.size() - 2] - used[nums.size() - 2] * robbed[0],
                                      robbed[nums.size() - 3] + nums[nums.size() - 1] - used[nums.size() - 3] * robbed[0]),
                                      robbed[nums.size() - 4] + nums[nums.size() - 1] - used[nums.size() - 4] * robbed[0]);
        // cout << "THIS " << robbed[nums.size() - 1] << '\n';
        return max(robbed[nums.size() - 1], robbed[nums.size() - 2]);
    }
};
