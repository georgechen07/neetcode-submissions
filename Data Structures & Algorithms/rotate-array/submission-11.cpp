class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) {
            return;
        }

        for (int i = 0; i < nums.size() / 2; ++i) {
            swap(nums[i], nums[nums.size() - 1 - i]);
        }

        for (int j = 0; j < k / 2; ++j) {
            swap(nums[j], nums[k - 1 - j]);
        }

        for (int a = 0; a < nums.size(); ++a) {
            cout << nums[a] << " ";
        }
        cout << '\n';

        for (int a = 0; a < (nums.size() - k) / 2; ++a) {
            swap(nums[k + a], nums[nums.size() - 1 - a]);
        }

        for (int a = 0; a < nums.size(); ++a) {
            cout << nums[a] << " ";
        }
        cout << '\n';
    }
};
/*
og
1 2 3 4 5 6 7 8     1000 2 4 -3
exp
5 6 7 8 1 2 3 4     4 -3 1000 2

reverse
8 7 6 5 4 3 2 1     -3 4 2 1000

0 1 2 3 4

size - k, size - 1 - k, size - 2 - k, k, k - 1
*/