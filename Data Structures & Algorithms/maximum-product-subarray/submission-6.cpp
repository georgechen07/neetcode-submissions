class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int products[1000] = {nums[0]};
        int maxProducts[1000] = {nums[0]};

        int firstNegative = 0;
        if (nums[0] < 0) {
            firstNegative = nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (products[i - 1] != 0) {
                products[i] = products[i - 1] * nums[i];
            } else {
                products[i] = nums[i];
            }

            if (firstNegative == 0 && nums[i] < 0) {
                firstNegative = products[i];
            }
            if (nums[i] == 0) {
                firstNegative = 0;
            }

            maxProducts[i] = products[i];
            if (maxProducts[i] <= 0 && (nums[i] > 0 || firstNegative > nums[i])) {
                maxProducts[i] /= firstNegative;
            }
            maxProducts[i] = max(maxProducts[i], maxProducts[i - 1]);
        }

        for (int k = 0; k < nums.size(); k++) {
            cout << k << " " << maxProducts[k] << " " << products[k] << '\n';
        }

        return maxProducts[nums.size() - 1];
    }
};
