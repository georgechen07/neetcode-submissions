class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low != high) {
            // cout << "low = " << low << " high = " << high << '\n';
            if (high == low + 1) {
                return min(nums[low], nums[high]);
            }
            int med = (high + low) / 2;
            if (nums[med] > nums[low] && nums[med] > nums[high]) {
                if (nums[high] > nums[low]) {
                    high = med;
                } else {
                    low = med;
                }
            } else if (nums[med] < nums[low] && nums[med] < nums[high]) {
                if (nums[high] < nums[low]) {
                    high = med;
                } else {
                    low = med;
                }
            } else {
                if (nums[high] > nums[low]) {
                    high = med;
                } else {
                    low = med;
                }
            }
        }

        return nums[high];
    }
};
