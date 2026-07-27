class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = 0;
        int b = 0;
        bool first_col = false;
        while (true) {
            if (!first_col) {
                a = nums[nums[a]];
            } else {
                a = nums[a];
            }
            b = nums[b];

            if (a == b && first_col) {
                return a;
            } else if (a == b) {
                b = 0;
                first_col = true;
            }
        }

        return 0;
    }
};
