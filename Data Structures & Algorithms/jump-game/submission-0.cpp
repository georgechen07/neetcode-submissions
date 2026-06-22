class Solution {
public:
    bool canJump(vector<int>& nums) {
        return recurse(nums, 0);
    }

    bool recurse(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }
        
        bool check = false;
        for (int i = nums[index]; i > 0; i--) {
            check |= recurse(nums, index + i);
            if (check == true) {
                return check;
            }
        }

        return check;
    }
};
