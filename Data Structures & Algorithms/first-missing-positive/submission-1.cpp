class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        if (nums[n - 1] <= 0) {
            return 1;
        }

        int index = 0;
        while(nums[index] <= 0) {
            index++;
        }

        int comp = 0;

        for (int i = index; i < n; i++) {
            if (comp >= 0 && nums[i] - comp > 1) {
                return comp + 1;
            }
            comp = nums[i];
        }

        if (nums[n - 1] > 0) {
            return nums[n-1] + 1;
        }

        return 1;
    }
};