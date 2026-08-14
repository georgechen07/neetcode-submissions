class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            missing ^= i;
        }
        for (auto const& num : nums) {
            missing ^= num;
        }

        return missing;
    }
};

/*
    000
    001
    010
    011
    100
    101
            110
    111

*/