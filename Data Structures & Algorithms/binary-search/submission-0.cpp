class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto l = nums.begin();
        auto r = nums.end();
        --r;

        while (l <= r) {
            auto mid = next(l, (r - l) / 2);
            if (*mid == target) {
                return mid - nums.begin();
            }
            if (*mid > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
