class Solution {
public:
    void sortColors(vector<int>& nums) {
        // track first 1 index
        // track first 2 index

        int one = 0;
        int two = 0;
        bool count = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (count) {
                    swap(nums[i], nums[one]);
                }
                swap(nums[i], nums[two]);
                ++one;
                ++two;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[two]);
                count = true;
                ++two;
            }
        }
    }
};